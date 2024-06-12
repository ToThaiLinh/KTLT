/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>

int main() {

    int x, y, z;                                    
    //Khai bao 3 bien kieu int
    int *ptr;                                       
    //Khai bao con tro kieu int

    scanf("%d %d %d", &x, &y, &z); //Nhap gia tri cho 3 bien kieu int
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z); //In ra gia tri cua 3 bien kieu int
    
    ptr = &x;  //Gan dia chi cua x cho con tro ptr
    *ptr += 100;//Tang gia tri bien x duoc ptr tro den them 100
    
    ptr = &y; //Gan dia chi cua y cho con tro ptr
    *ptr  += 100;//Tang gia tri bien y duoc ptr tro den them 100
    
    ptr = &z;//Gan gia tri cua z cho con tro ptr
    *ptr += 100;//Tang gia tri cua bien x duoc ptr tro den them 100
    
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    //In ra gia tri cua 3 bien x, y, z sau khi da tang them 100

    return 0;
}

