/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <bits/stdc++.h>
using namespace std;
int a[1000], n;//Khai bao mang a kieu int luu gia tri dau vao, bien n kieu int 
int mem[1000]; //# mang ghi nho loi giai cua cac bai toan con da duoc giai

void init(){
    memset(mem, -1, sizeof(mem));
    //Khoi tao cac phan tu cua mem bang -1
}

//# Quy hoach dong, 
//# Ham  list(i) tra ve do dai cua day con tang dai nhat ket thuc boi a[i]
int lis(int i) {
    if(mem[i] != -1) {
        //neu da co loi giai thi tra ve
        return mem[i];
    }
    int res = 1;
    //khoi tao res = 1 luu ket qua cua list(i)
    for(int j = 0; j < i; j++) {
        //Duyet qua tung phan tu neu co phan tu nao be hon a[i]
        //Cong vao ket qua res
        if(a[j] < a[i]) {
            res = max(res, 1 + lis(j));
        }
    }
    //Luu vao trong mang ket qua mem[i]
    mem[i] = res;
    return res;
    
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            //De quy truy vet loi giai
            trace(j);
            break;
        }
    }
    //In ra a[i]
    cout << a[i] << " ";
}

int main(){
    init();//Khoi tao mang mem
    cin >> n;//Nhap gia tri cua n
    for(int i = 0; i < n; i++) cin >> a[i];
    // Nhap gia tri tung phan tu cua mang a
    int res = 1, pos = 0;
    //res la do dai cua day con tang dai nhat
    //pos vi tri cua phan tu cuoi cung trong day con tang dai nhat
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;// In gia tri day con dai nhat
    trace(pos);//In ra day con tang dai nhat
    return 0;
}
//To Thai Linh 20215414
