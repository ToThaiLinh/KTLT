/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */

#include<bits/stdc++.h>

using namespace std;

int n;//Do dai cua chuoi 
string str;// Chuoi nguoi dung nhap vao
int res = 0;//So luong chuoi con co '0' va '1' bang nhau
map<int, int> m;
//Key la do chenh lech giua so luong chu so '0' va chu so '1'
//Value la so lan xuat hien do chenh lech do

void inputData(){
    cin >> str; // Nhap chuoi str tu nguoi dung
    n = str.length(); // Tinh do dai cua chuoi
}

// Ham tinh tong cac so tu 1 den b
int calc(int b){
    int foo = 0;
    for (int i = 1; i < b; i++){
        foo += i;
    }
    return foo;
}

void solve(){
    int slg0 = 0, slg1 = 0; // So luong cac so 0 va 1
    map<int, int>::iterator it;

    for (int i=0; i<n; i++){
        if (str[i] == '0') slg0++; // Nhung ky tu la '0' thi tang so luong slg0 len 1
        else slg1++; // Nguoc lai tang so luong so 1 len 1

        int tmp = slg1 - slg0; // Do chenh lech giua so luong so 0 va 1
        it = m.find(tmp); // Tim kiem chenh lech trong map
        if (it != m.end()){ // Neu do chenh lech da ton tai trong map
            it->second += 1; // Tang so luong cap so 0 va so 1 co cung do chenh lech 
        }else{//Neu khong tim thay do chenh lech trong map
            m.insert({tmp, 1}); // them do chenh lech vao map voi value la 1
        }
    }

    it = m.begin();
    while (it != m.end()){
        res += calc(it->second); // Tinh tong cac cap co cung do chenh lech 
        if (it->first == 0) res += it->second; 
		// Neu do chenh lech la 0 thi cong them vao so luong do chenh lech nay
        
        it++;
    }
}

int main(){
    inputData();//Nhap gia tri tu nguoi dung
    solve();//Tim so chuoi con co so luong so '0' va '1' bang nhau
    cout << res; // In ket qua
    return 0;
}
//To Thai Linh 20215414
