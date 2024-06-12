/*To Thai Linh 20215414 
Ma lop thuc hanh 732826*/ 
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
	//Khai bao 2 bien n va M kieu int 
	//de luu so luong qua can va khoi luong M
    int n, M;
    cin >> n >> M;//Nhap gia tri cho 2 bien n va M
    //Khai bao mang m gom n + 1 phan tu 
	//luu khoi luong cua tung qua can
    int m[n+1];
    //Nhap gia tri cho mang m
    for (int i = 1; i <= n; ++i) cin >> m[i];
    //Khai bao mang x luu trang thai chon can
    // -1 neu chon dau tru, 1 neu chon dau cong
    int x[n+1];
    //Khai bao stack s de luu cac trang thai khi thuc hien de quy
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    //Khoi tao trang thai ban dau 
    s.push(state(1, -1));
    while (!s.empty()){
    	//Lay phan tu dau tien cua stack
        state &top = s.top();
        if (top.i > n){
        	//Neu vuot qua so luong qua can va tong bang M thi in ket qua
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
                //Thoat khoi chuong trinh
            }
            //Loai bo phan tu dau stack 
            s.pop();
            continue;
        }
        if(top.j > -1) {
        	sum -= m[top.i] * x[top.i];
        }
        if(top.j > 1) {
        	s.pop();
        	continue;
        }
        x[top.i] = top.j;
        //Gan dau top.j cho vi tri top.i trong mang a
        sum += m[top.i] * x[top.i];
        //Ting tong khoi luong
        s.push(state(top.i + 1, -1));
        //Them trang thai tiep theo vao ngan xep
        ++top.j;
        //Tang bien dau them 1 don vi 
        
        
    }
    cout << -1;
    //Neu khong tim thay in ra -1

    return 0;
}
//To Thai Linh 20215414 
