/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    //Ham hoan vi vong tron 3 bien bang cach truyen tham chieu 
    int tmp = x;
    //Khai bao mot bien tmp kieu int va gan gia tri cua x cho tmp
    x = y;
    //Gan gia tri cua y cho x
    y = z;
    //Gan gia tri cua z cho y
    z = tmp;
    //Gan gia tri cua tmp cho z
}

int main() {
    int x, y, z;
    //Khai bao 3 bien x, y, z kieu int 
    
    scanf("%d %d %d", &x, &y, &z);
    //Nhap gia tri cho 3 bien x, y, z
    
    printf("Before: %d, %d, %d\n", x, y, z);
    //In ra ket qua truoc khi hoan doi 
    rotate(x, y, z);
    //Goi den ham rotate hoan doi gia tri 3 bien
    printf("After: %d, %d, %d\n", x, y, z);
    //In ra ket qua sau khi da hoan doi vong tron
    
    return 0;
}
//To Thai Linh 20215414
