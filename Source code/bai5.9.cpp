/* To Thai Linh 20215414
Ma lop thuc hanh 732826 */

#include <bits/stdc++.h>
using namespace std;
//Dinh nghia cau truc mot khoi co 3 chieu x, y, z
typedef struct {
    int x, y, z;
} block;
int n;//So luong khoi
block a[100];//Mang luu tru cac khoi
int maxh[100];//mang luu tru chieu cao toi da moi khoi

void input(){
    cin >> n;//Nhap so luong khoi
    if (n == 0) exit(0);//Neu khong co khoi nao, thoat
    int x, y, z;//Bien luu tru kich thuoc
    for (int i = 1; i <= n; i++){ //Sua tu n <= n thanh i <= nx
        cin >> x >> y >> z;
        //Luu tru kich thuoc vao mang a trong 3 su thay doi khac nhau
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;
        a[3 * i - 1].x = y;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = x;
        a[3 * i].x = z;
        a[3 * i].y = x;
        a[3 * i].z = y;
    }
}

int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
	//Neu chieu cao toi da da duoc tinh thi tra ve ngay
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;//Khoi tao chieu cao toi da bang chieu cao cua hinh hop
    for(int j = 1; j <= n; j++){
        if (a[i].x < a[j].x && a[i].y < a[j].y || 
            a[i].x < a[j].y && a[i].y < a[j].x){
            maxh[i] = max (maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}
 
int main(){
    int cnt = 1;//Bien dem cho cac truong hop thu nghiem
    while(1){
        int res = 0;//Bien luu tru ket qua
        input();//Goi ham nhap du lieu
        for(int i = 1; i <= 3 * n; i++){
        	//Tim chieu cao toi da giua cac thap co the
            res = max(res, dp(i));
        }
        //in ket qua cho truong hop thu nghiem hien tai
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}
//To Thai Linh 20215414
