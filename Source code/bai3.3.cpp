/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# so thanh pho va ma tran chi phi
int cmin = INT_MAX; //# chi phi di lai nho nhat giua cac thanh pho khac nhau
int best = INT_MAX; //# tong chi phi nho nhat can tim, ban dau dat gia tri vo cung lon INT_MAX = 2^31-1
int curr; //# tong chi phi toi thoi diem hien tai
int mark[MAX]; //# danh dau nhung thanh pho da di
int x[MAX]; //# luu tru cac thanh pho da di

//# Doc du lieu dau vao
void input(){
    cin >> n;//Nhap gia tri cho n
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];//nhap chi phi cho tung thanh pho
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
            //tim chi phi nho nhat giua cac thanh pho
        }
}

//# Thuat toan quy lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if(!mark[i]) {
            x[k] = i;//Den lan k tham thanh pho thu i
            mark[i] = 1;//Danh dau thanh pho i la da tham
            curr += c[x[k - 1]][i];//Tinh toan chi phi hien tai
            if(k == n) best = min(best, curr + c[i][1]);
            //Neu tham het n thanh pho thi tinh chi phi tot nhat
            else if(curr + cmin * (n - k + 1) < best) TRY(k + 1);
            //Tinh khoang uoc luong khi het n - k thanh pho con lai
            //Neu nho hon best thi tiep tuc di den thanh pho tiep theo
            mark[i] = 0;
            //Dat lai bien danh dau mark la 0
            curr -= c[x[k - 1]][i];
            //Dat lai gia tri chi phi
        }
    }
}

int main() {
    input();//Goi den ham nhap gia tri dau vao
    x[1] = 1;//Thanh pho 1 da di 
    TRY(2);//De quy voi thanh pho thu 2
    cout << best;//In ra chi phi nho nhat
    return 0;
}
//To Thai Linh 20215414
