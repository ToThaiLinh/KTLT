/* To Thai Linh 20215414
Ma lop thuc hanh 732826 */

#include <bits/stdc++.h>
#include <complex> 
using namespace std;

void input (vector<int> &a, int n) {
//Ham nhap du lieu nhan vector a va so nguyen n 
    int x;
    for(int i = 0; i < n; i++) {
        cin>>x; a.push_back(x); 
		//Doc gia tri x va them gia tri vao cuoi vector a
    }
}

//Kieu du lieu cho phep dung so phuc
const double PI = acos(-1); //Hang so PI
void fast_fourier(vector <complex<double> > &p, bool invert) {
	//Ham bien doi fourier nhanh
    int n = p.size(); //Luu tru kich thuoc vector p
    if (n == 1) 
        return;
    //Kich thuoc vector la 1 thi dung    
    vector<complex<double> > p_0(n/2), p_1(n/2);
    //Chia p thanh hai thanh phan, moi phan co kich thuoc n/2
    for (int i = 0; 2*i < n; i++) {
        p_0[i] = p[2*i];
        p_1[i] = p[2*i+1];
    }
    fast_fourier(p_0, invert); //De quy tren p_0
    fast_fourier(p_1, invert); //De quy tren p_1

    double angle = 2*PI/n * (invert ? -1 : 1); //Tinh goc quay
    complex<double>  matrix_element(1), martric_element_n(cos(angle), sin(angle));
    //Khai bao so phuc
	for (int i = 0; 2*i < n; i++) {
		//Bien doi fourier
        p[i] = p_0[i] + matrix_element * p_1[i];
        p[i + n/2] = p_0[i] - matrix_element * p_1[i];
        if (invert) {
            p[i] /=  2;
            p[i + n/2] /= 2;
        }
        matrix_element = matrix_element * martric_element_n;
        //Cap nhat gia tri, chuan bi vong lap tiep theo
    }
}
vector<int> polynomial_multiply(vector<int> &a, vector<int> &b) {
    vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
    //Tao vector fa va fb tu a va b
	int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    //Tim luy thua    
    fa.resize(n); //Thay doi kich thuoc fa
    fb.resize(n); //Thay doi kich thuoc fb
    fast_fourier(fa, false); //Bien doi fourier tren fa
    fast_fourier(fb, false); //Bien doi fourier tren fb

    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
        //Nhan cac phan tu tuong ung cua fa va fb
    fast_fourier(fa, true);
    //Bien doi fourier nguoc
    vector<int> result(n); //Tao vector result
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real()); //Luu phan thuc trong fa
    return result;
}

int main () {
    int m,n;
    vector<int> a, b; //Tao vector
    cin >> n; 
    input(a,n+1); //Nhap vector a co n+1 phan tu
    cin>>m;
    input(b,m+1); //Nhap vector b co m+1 phan tu
    vector<int> c = polynomial_multiply(a,b);
	//Nhan da thuc a va b xong luu ket qua vao vector c
    int h = m + n + 1;
    int xor_c = c[0] ^ c[1]; //Khoi tao
    for (int i = 2; i < h; i++)
        xor_c = xor_c^c[i]; //Thuc hien XOR
    cout << endl<< xor_c;
    return 0;
}//To Thai Linh 20215414 
