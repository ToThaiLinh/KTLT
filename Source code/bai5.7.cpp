/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;//Khai bao bien n kieu int de luu so luong thon
    cin >> n;//Nhap so luong thon
    //Khoi tao 2 bien ans luu ket qua, sum luu tong so tien
    int ans = 0, sum = 0;
    //Duyet qua tat ca cac thon
    while(n--){
    	//Khai bao 2 bien k va t luu so nha trong thon
    	//t danh dau xem thon do giau hay ngheo
        int k, t;
        cin >> k >> t;//Nhap vao k va t
        //Neu thon do giau thi tinh tonh so tien
        //Ket qua bang max cua ans va -sum
        if(t == 1) {
        	while(k--){
	            int a;
	            cin >> a;
	            sum += a;
	            ans = max(ans, -sum);
        	}
        }
        //Neu thon do ngheo thi tinh tong so con lai
        //Ket qua bang max cua ans va sum
        else if(t == -1) {
        	while(k--) {
        		int a;
        		cin >> a;
        		sum -= a;
        		ans = max(ans, -sum);
        	}
        }     
    }
    //In ket qua
    cout << ans;
}
// To Thai Linh 20215414

