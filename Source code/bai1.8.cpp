/*To Thai LinhLinh 20215414
Ma lop thuc hanh: 732826*/

#include <bits/stdc++.h>

void allocate_mem(int ***mt, int m, int n){
    *mt = new int*[m];                      
    //Cap phat dong m con tro kieu int
    for(int i = 0; i < m; i++) {            
        (*mt)[i] = new int[n];              
        //Cap phat dong n ô nho duoc tro boi m[i]
    }
}


void input(int **mt, int m, int n){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("mt[%d][%d] = ",i, j);
            scanf("%d", *(mt + i) + j);    
            //Nhap du lieu cho mt[i][j] co dia chi *(m + i) + j
        }
    }
} 

void output(int **mt, int m, int n){
     for(int i = 0; i < m; i++) {
         for(int j = 0; j < n; j++) {
             printf("%d ",*(*(mt + i) + j));//In du lieu mang 2 chieu
         }
         printf("\n");
     }
     
}

int process(int **mt, int m, int n){
    int tong = 0;
    //Khoi tao mot bien tong kieu int bang 0
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(*(*(mt + i) + j) % 2 == 0) {
                    tong += *(*(mt + i) + j);
                }
            }
            //Kiem tra dieu kien neu mt[i][j] chan thi cong vao tong
        }
 
    return tong;
}

void free_mem(int **mt, int m, int n){
    for(int i = 0; i < m; i++) {
        delete [] *(mt + i); //Xóa tung hang cua mt
    }
    delete [] mt;//Xoa mang luu dia chi cua tung hang
}

int main(){
    int m, n, **mt;//Khai bao 2 bien kieu int và 1 con tro kieu int
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);//Nhap gia tri cua m và n
    allocate_mem(&mt, m, n);//Goi den ham cap phat bo nho cho mang 2 chieu
    input(mt, m, n);//Goi ham nhap mang
    output(mt, m, n);//Goi ham in ra mang
    printf("The sum of all even elements is %d", process(mt, m, n));//In ra tong 
    free_mem(mt, m, n);//Giai phong bo nho
    return 0;
}
