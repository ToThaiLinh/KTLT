/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;
//Su dung khong gian ten std
struct Complex {
    double real;
    double imag;
};
/*Khai bao mot struct Complex
Co 2 truong du lieu real kieu int va imag kieu int*/

Complex operator + (Complex a, Complex b) {
    //Da nang hoa toan tu + voi doi so la 2 so phuc
    Complex t;
    //Khai bao mot so phuc t
    t.real = a.real + b.real;
    //Tinh phan thuc cua t
    t.imag = a.imag + b.imag;
    //Tinh phan ao cua t
    return t;//Tra ve so phuc t
}

Complex operator - (Complex a, Complex b) {
    //Da nang hoc toan tu - voi doi so la 2 so phuc
    Complex t;
    //Khai bao mot so phuc t
    t.real = a.real - b.real;
    //Tinh phan thuc cua t
    t.imag = a.imag - b.imag;
    //Tinh phan ao cua t
    return t;
    //Tra ve so phuc t
}

Complex operator * (Complex a, Complex b) {
    //Da nang hoa toan tu voi phep *
    Complex t;
    //Khai bao mot so phuc t
    t.real = a.real * b.real - a.imag * b.imag;
    //Tinh phan thuc cua t
    t.imag = a.real * b.imag + a.imag * b.real;
    //Tinh phan ao cua t
    return t;
    //Tra ve so phuc t
}

Complex operator / (Complex a, Complex b) {
    Complex t;
    //Khai bao mot so phuc t
    t.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    //Tinh phan thuc cua t
    t.imag = (-a.real * b.imag + a.imag * b.real)/ (b. real * b.real  + b.imag * b.imag);
    //Tinh phan ao cua t
    return t;
    //Tra ve so phuc t
}

ostream& operator << (ostream& out, const Complex &a) {
    //Da nang hoa toan tu << voi doi so la dau ra out va so phuc a
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << 
    std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    //In ra so phuc voi dinh dang a +/- bi lam tron 2 chu so thap phan
    return out;
    //Tra ve luong dau ra
}

int main() {
    double real_a, real_b, img_a, img_b;
    //Khai bao 4 bien kieu double
    cin >> real_a >> img_a;
    //Nhap gia tri cho 2 bien real_a va img_a
    cin >> real_b >> img_b;
    //Nhap gia tri cho 2 bien real_b va img_b
    
    Complex a{real_a, img_a};
    //Gan gia tri cho so phuc thu nhat
    Complex b{real_b, img_b};
    //Gan gia tri cho so phuc thu 2
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
//To Thai Linh 20215414
