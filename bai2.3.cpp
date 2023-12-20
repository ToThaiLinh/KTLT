/*To Thai Linh 20215414 
Ma lop thuc hanh: 732826*/
#include <stdio.h>

int get_value(int x, int a = 2, int b = 1, int c = 0) {
    /*Ham tra ve gia tri kieu int voi 4 tham so la x kieu int
    va 3 tham so ngam dinh la a = 2, b = 1, c = 0*/
    return a * x * x + b * x + c;
    //Tra ve gia tri cua ax^2 + bx + c
}
    
int main(){
    int x;//Khai bao mot bien x kieu int
    scanf("%d", &x);//Nhap gia tri cho x
    
    int a = 2; //# giá tr? m?c ð?nh c?a a
    int b = 1; //# giá tr? m?c ð?nh c?a b
    int c = 0; //# giá tr? m?c ð?nh c?a c
    
    scanf("%d %d %d", &a, &b, &c);
    //Nhap gia tri cho 3 bien a, b , c
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    //In ra ket qua khi goi ham voi 1 tham so x
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    //In ra ket qua khi goi ham voi 2 tham so x va a
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    //In ra ket qua khi goi ham voi 3 tham so x, a, b
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    //In ra ket qua khi goi ham voi 3 tham so x, a, b, c
    
    return 0;
}
//To Thai Linh 20215414
