/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <stdio.h>

int main() {
    int x, y, z; //Khai bao 3 bien kieu int
    int* ptr;   //Khai bao con tro kieu int

    printf("Enter three integers:");
    scanf("%d %d %d", &x, &y, &z); //Nhap v�o gi� tri cho 3 bien nguy�n x, y, z
    printf("\nThe three integers are:\n");
    
    ptr = &x; //G�n dia chi cua bien x cho con tro ptr
    printf("x = %d\n", *ptr);      
    
    ptr = &y; //G�n dia chi cua bien y cho con tro ptr
    printf("y = %d\n", *ptr);
    
    ptr = &z; //G�n dia chi cua bien z cho con tro ptr
    printf("z = %d\n", *ptr);       
    
    return 0;
}//To Thai Linh 20215414
