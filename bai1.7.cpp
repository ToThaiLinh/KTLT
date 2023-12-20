/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/


#include <stdio.h>
#include <stdlib.h>

int *a;     //Khai bao mot con tro a kieu int
int n, tmp; //Khai bao 2 bien n va tmp kieu int

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n); //Nhap gia tri cua n
    
    a = (int*)malloc(n * sizeof(int));         
    //Cap phat dong n o nho co kich thuoc sizeof(int) va gan dia chi cho a
    
    for(int i = 0; i < n; i++) //Duyet va nhap tung gia tri cho mang a
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));//In ra gia tri tung phan tu trong mang a
    printf("\n");
    
    for(int i = 0; i < n - 1; i++) { //Duyet qua tat ca cac phan tu cua con tro
        for(int j = i + 1; j < n; j++) { //Duyet tu phan tu thu i + 1 d?n het 
            if(*(a + i) > *(a + j)) {           
    /*So sanh 2 phan tu tu i + 1 cho den het de tim gia tri nho nhat cua
    phan tu thu i roi dao gia tri*/
                tmp = *(a + i);                 
                *(a + i) = *(a + j);   
                *(a + j) = tmp;
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i)); //In ra gia tri cua tung phan tu sau khi sap xep
    printf("\n");
    
    delete [] a; //Giai phong vung nho 
    return 0;
}
//To Thai Linh 20215414

