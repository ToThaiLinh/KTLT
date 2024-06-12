/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
using namespace std;
//Ham de quy tinh c(k, n) = c(k -1, n -1) + C(k, n - 1)
int binom(int n, int k) {
    if (k > n) return 0;//Truong hop co so neu k > n thi tra ve 0
    if (k == 0) return 1;//Truong hop co so neu k == 0 thi tra ve 1
    //De quy
    return binom(n-1, k) + binom(n-1, k-1);
}
int c[1000][1000];//Khai bao mang c de luu gia tri cac c[n][k] 
int binom2(int n, int k){
    for(int i = 0; i <= n; i++) {
        //khoi tao c[0][i] = 1
        c[0][i] = 1;
        //Tinh gia tri cac C(0, i) den C(i, i)
        for(int j = 1; j <= i; j++) {
            //Cong thuc newton
            c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
        }
    }
    //Tra ve gia tri C(k, n)
    return c[k][n];
}

int main() {
    int m;//khai bao bien m kieu int
    cin >> m;//Nhap gia tri cho m
    //In ra cac gia tri tu C(0, 1), C(1, 1),C(0, 2), ..., C(n, n) bang cach binom(n, k)
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    //In ra cac gia tri tu C(0, 1), C(1, 1),C(0, 2), ..., C(n, n) bang cach binom2(n, k)
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
//To Thai Linh 20215414
