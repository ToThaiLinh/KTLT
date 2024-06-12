/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */ 
#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, all[100];//Khai bao lai bien All thanh all

void init(){
    for (int i = n; i >= 1; --i){
        all[i] = all[i+1] + v[i];
    }
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + all[i] <= best || sumM > M) return;//Thay doi return 0; thanh return;
    if (i > n){
        best = sumV;//Them dau ;
        return;//Thay doi return 0; thanh return;
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}
//To Thai Linh 20215414 

