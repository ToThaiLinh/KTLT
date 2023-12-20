/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //i: bieu dien loi giai bo phan cap i, truoc do la x1, x2,..., x[i - 1]
    //j: gia tri ung cu vien dang xet cho vi tri x[i]
    //old_L so ky tu 1 lien tiep o cuoi day x1, x2,..., x[i - 1]
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;//Khai bao 2 bien n, k kieu int
    cin >> n >> k;//Nhap gia tri cho 2 bien n va k
    int x[n+1];//Khai bao mang chua n + 1 phan tu de luu ket qua
    stack<state> s;//Khai bao stack s chua cau truc state
    //# number of consecutive suffix 1
    int L = 0;//Khoi tao bien L kieu int bang 0
    s.push(state(1, 0));//Khoi tao phan tu dau tien cua stack la 1, 0, 0
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            //In ket qua
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            //Loai bo khoi ngan xep
            s.pop();
            continue;
        }
        
        //# Kh? d? quy
        //Back track
        //Kiem tra ung cu vien neu lon hon 0 thi gan old_L cho L
        if(top.j > 0) {
            L = top.old_L;
        }
        //Neu moi day con da tham thi loai bo
        if(top.j > 1) {
            s.pop();
            continue;
        } 
        //Neu chua co k so 1 lien tiep hoac ung cu vien bang 0
        if(L + 1 < k || top.j == 0) {
            x[top.i] = top.j;//Gan vi tri x[i] = j
            top.old_L = L; // Cap nhat gia tri cua old_L neu j > 0
            L = top.j ? L + 1 : 0;
            //Cap nhat gia tri cua L neu top.j > 0 thi tang 1
            //Neu top.j = 0 thi khong tang 
            s.push(state(top.i + 1, 0));
            //Them trang thai moi vao ngan xep stack 
        }
        //Tang gia tri cua ung cu vien
        ++top.j;
    }
    return 0;
}
//To Thai Linh 20215414
