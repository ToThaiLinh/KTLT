/* To Thai Linh 20215414
Ma lop thuc hanh: 7328268*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;//Khai bao bien n kieu int luu so nam nhap vao 
    cin >> n;//Nhap so nam
    bool found = false;//Bien found kiem tra xem co nam nhuan trong danh sach khong
    while(n){
        int a;//Khai bao bien a kieu int nhan gia tri nam
        cin >> a;//Nhap vao nam 
        //Kiem tra dieu kien nam nhuan
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0)) {
        	found = true;//Gan bien found bang true ket thuc vong lap
        	break; 
            
        }
        n--; 
    }
    if (found) cout << "Yes";//In ra Yes neu found true
    else cout << "No";//truong hop nguoc lai in ra No
}
//To Thai Linh 20215414 


