/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>

int cube(int x) {
    //Ham tra ve kieu int va nhan tham so kieu int
    return x * x * x;
    //Tra ve lap phuong cua x
}

double cube(double x) {
    //Ham tra ve kieu double va nhan tham so kieu doule 
    return x * x * x;
    //Tra ve lap phuong cua x
}

int main() {
    int n;//Khai bao mot bien n kieu int
    double f;//Khai bao mot bien f kieu double
    scanf("%d %lf", &n, &f);
    //Nhap gia tri cho n va f
    
    printf("Int: %d\n", cube(n));
    //In gia tri tra ve cua ham cube khi nhan doi so kieu int
    printf("Double: %.2lf\n", cube(f));
    //In gia tri tra ve cua ham cube khi nhan doi so kieu double
    return 0;
}
//To Thai Linh 20215414
