/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    //Truong hop co so dung de quy
    if (b == 0) return a;
    //De quy
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    //Khu de quy khi nao b == 0 thi dung lai
    while(b) {
        a %= b;//a = du cua a / b
        swap(a, b);//Doi cho a va b
    }
    return a;
}

int main() {
    int a, b;//Khai bao 2 bien a va b kieu int
    cin >> a >> b;//Nhap gia tri cho 2 bien a va b
    cout << gcd(a, b) << endl << gcd2(a, b);
    //Tinh uoc chung cua a va b theo 2 cach
    return 0;
}
//To Thai Linh 20215414
