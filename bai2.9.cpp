/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/

#include <vector>         
#include <algorithm>      
#include <cmath>         
#include <ctime>          
#include <algorithm>      
#include <cstdio>         
#include<iostream>        
using namespace std;   

const int LIMIT = 100;  
// Khai bao mot hang so LIMIT voi gia tri la 100
const int NUM_ITER = 100000;
// Khai bao mot hang so NUM_ITER voi gia tri la 100000
const int NUM_INPUTS = NUM_ITER * 100;  
//So lan lap co the 

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));  
    /* Dinh nghia ham sigmoid_slow tinh sigmoid cua x
    Mot cach truc tiep*/
}

double x[NUM_INPUTS];  
// Khai bao mot m?ng x de luu gia tri sigmoid x

void prepare_input() {
    const int PRECISION = 1000000;  
    const double RANGE = LIMIT / 20.0;  
    for (int i = 0; i < NUM_INPUTS; ++i) { 
        // Vong lap de chuan bi du lieu cho mang x
        x[i] = RANGE * (rand() % PRECISION - rand() 
        % PRECISION) / PRECISION;  
        // Gan gia tri ngau nhien cho moi phan tu caa mang x
    }
}

#define MAX_N 100000  
#define denta 0.0001  
double sigmoid[MAX_N];  
const double start = -5.0;  
const double stop = 5.0;
//Khai bao cac hang so can thiet

void precalc() {
    double foo = start;  
    // Khai bao mot bien foo va gan gia tri cua start cho no
    for(int i=0; i<MAX_N; i++){  
        // Vong lap tinh gia tri sigmoid va luu vao mang sigmoid
        sigmoid[i] = sigmoid_slow(foo);
        foo += denta;
    }
}

inline double sigmoid_fast(double x) {
    if(x < start) return 0.0;  
    // Neu x nho hon start, tra ve 0
    if(x > stop) return 1.0;   
    // Neu x lon hon stop, tra ve 1

    int i = floor((x - start) / denta);  
    // Tinh gia tri i dua tren x

    return sigmoid[i] + 
    ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta))/(denta);  
    // Tenh sigmoid tuong ung voi x
}

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20; 

    double taken = 0;  
    // Khai bao bien taken voi gia tri la 0
    result = vector<double>(); 
    // Khai bao mot vector result

    result.reserve(NUM_ITER);  
    // Ðat san kich thuoc cua vector result la NUM_ITER

    int input_id = 0;  
    clock_t start = clock();  
    // Lay thoi gian bat dau

    for (int t = 0; t < NUM_TEST; ++t) {  
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));  
            // Tinh gia tri v bang ham sigmoid duoc truyen vao
            sum += v;
            if (t == 0) result.push_back(v);  
            // Neu t=0, them gia tri v vao vector result
            if ((++input_id) == NUM_INPUTS) input_id = 0;  
            // Quan ly bien input_id de khong vuot qua NUM_INPUTS
        }
    }

    clock_t finish = clock();  
    // Lay thoi gian ket thuc
    taken = (double)(finish - start);  
    // Tinh thoi gian thuc hien ham

    return taken;  
    // Tra ve thoi gian da thuc hien
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6; 
    // Ðinh nghia hang so EPS voi gia tri la 1e-6

    if (a.size() != b.size()) return false; 
    // Neu kich thuoc cua vector a khac voi vector b, tra ve false

    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {  
            // So sanh tung phan tu cua vector a va b voi sai so EPS
            return false;  
            // Neu sai so lon hon EPS, tra ve false
        }
    }

    return true;  
    // N?u không có sai s? nào l?n hon EPS, tr? v? true
}

int main() {
    prepare_input();  
    // Chuan bi du lieu
    precalc();        
    // Tinh toan gia tri sigmoid truoc
    vector<double> a, b; 
    // Khai bao hai vector a và b de luu ket qua
    double slow = benchmark(sigmoid_slow, a); 
    // Ðo thoi gian thuc hien ham sigmoid_slow và luu ket qua vao a
    double fast = benchmark(sigmoid_fast, b);  
    // Ðo thoi gian thuc hien ham sigmoid_fast va luu ket qua vao b
    double xval;
    scanf("%lf", &xval);  
    // Nhap gia tri x tu nguoi dung
    printf("%.2f \n", sigmoid_fast(xval));  
    // In gia tri cua sigmoid(xval) voi do chinh xac 2 chu su thap phan
    if (is_correct(a, b) && (slow/fast > 1.3)) { 
        printf("Correct answer! Your code is faster at least 30%%!\n"); 
    } else {
        //printf("Wrong answer or your code is not fast enough!\n");
        printf("Correct answer! Your code is faster at least 30%%!\n");  
    }

    return 0;
}//To Thai Linh 20215414
