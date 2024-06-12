/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;//khai bao bien n kieu int luu so diem nhap vao
    cin >> n;//Nhap so luong diem
    //Khai bao cac bien luu so luong loai diem
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    //Vong lap qua tat ca cac diem
    while(n--){
        int a;//Khai bao bien a kieu int luu diem
        cin >> a;//Nhap diem
        //Ung voi moi diem se tuong ung voi loai diem so tang len
		if (7 <= a && a < 8.5) ++B;
		else if (5.5 <= a && a < 7) ++C;
		else if (8.5 <= a) ++A;
		else if (4 <= a && a < 5.5) ++D;
        else if (a < 4) ++F;
	}
	//In ket qua
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
// To Thai Linh 20215414


