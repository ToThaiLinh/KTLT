/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    return sqrt(x * x + y * y);//tra ve gia tri cua canh huyen
}

int main(){
    float x, y; //Khai bao 2 bien kieu float 
    scanf("%f%f", &x, &y);//Nhap gia tri 2 bien x va y
    
    float z = get_hypotenuse(x, y);//Goi den ham tinh canh huyen roi gan cho z
    printf("z = %.2f\n", z);//In ket qua voi 2 chu so thap phan sau dau phay
    
    return 0;
}
//To Thai Linh 20215414
