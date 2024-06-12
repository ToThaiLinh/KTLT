/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
using namespace std;

int n;//Khai bao bien n kieu int
int X[100], Y[100]; //luu toa do cac buoc di chuyen cua quan ma
int mark[100][100]; //# Danh dau vi tri cac o ma quan ma da di chuyen qua

//# Mang hx, hy mo ta 8 vi tri quan ma co the di chuyen ke tu vi tri hien tai 
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra day cac di chuyen tim duoc
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuat toan quay lui 
void TRY(int k){
    for(int i = 0; i < 8; i++){
        //vong lap de tinh cac nuoc di co the xuat phat tu X[k - 1] va Y[k - 1]
        int xx = X[k-1] + hx[i];//Tinh gia tri toa do X[k] 
        int yy = Y[k-1] + hy[i];//Tinh gia tri toa do Y[k]
        if( (!mark[xx][yy]) && (1 <= xx) && (xx <= n) && (1 <= yy) && (yy <= n) ) {
            mark[xx][yy] = 1;//Gan gia tri cho mark bang 1 de danh dau da kiem tra
            X[k] = xx;//Gan gia tri cua xx cho toa do X[k]
            Y[k] = yy;//Gan gia tri cua yy cho toa do Y[k]
            if(k == n * n) print_sol();//Ket thuc de quy in ra ket qua
            else TRY(k + 1);//De quy cho lan lap tiep theo
            mark[xx][yy] = 0;//Dat lai cho mark gia tri 0 de quay lui
        }
    }
}

int main(){
    cin >> n;//Nhap gia tri cho n
    mark[1][1] = 1;//Danh dau o (1,1) da di qua
    X[1] = Y[1] = 1;//Gan toa do cho X[1] va Y[1]
    TRY(2);//Kiem tra den buoc di thu 2
    return 0;
}
//To Thai Linh
