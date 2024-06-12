/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/

#include <bits/stdc++.h>

using namespace std;

//Khai bao cac bien toan cuc
//T la so test case, t[20][2] la gia tri cac test case
//H la so vi tri khac nhau
//N la do dai xau
//mang a luu gia tri tai moi vi tri
//sum luu tong cua cac phan tu 
int T, t[20][2], H, N;
int a[20], sum = 0;

void TRY(int i){
	//Ham de quy thu tat ca cac gia tri cho bit tai vi tri i trong xau
    if (i > N) {
    	//Neu da xet den tat ca cac vi tri trong xau
        for (int i = 1;  i <= N; ++i){
            if (sum != H) return;
            //Neu tong cac phan tu khong bang H thi khong in 
            cout << a[i];
            //In ra tung phan tu
            if (i == N) cout << endl;
        }
        return;
    }
    int old_S = sum;
    //Luu gia tri cua sum vao old_S de luu trang thai truoc thay doi
    a[i] = 0;
    //Khoi tao phan tu dau tien bang 0
    TRY(i+1); //De quy
    sum = old_S;//Quay lui

    if (sum < H) {
    	//Truong hop chua du khoang cach hamming
        a[i] = 1;//Tai vi tri i gan bang 1
        ++sum;//Tang tong
        TRY(i+1);//De quy
        sum = old_S;//Quay lui
    }
}

int main(int argc, const char** argv) {
    cin >> T;//Nhap vao so test case
    //Nhap gia tri cua tung test case
    for (int i = 0; i < T; i++) {
        cin >> t[i][0];
        cin >> t[i][1];
    }
    for (int i = 0; i < T; i++) {
        N = t[i][0];//Lay gia tri do dai xau
        H = t[i][1];//Lay gia tri hamming
        cout << endl;
        TRY(1);//De quy voi phan tu dau tien
    }
    return 0;
}
//To Thai Linh 20215414
