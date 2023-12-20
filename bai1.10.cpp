/*To Thai Linh 20215414
Ma lop thuc hanh: 732826
Bai 1.10*/ 

#include <bits/stdc++.h>
using namespace std;

void allocate(int ***mt, int n) {
//Ham cap phat bo nho dong cho mang 2 chieu 
	*mt = new int*[n];
	//Cap phat bo nho cho cac hang 
	for(int i = 0; i < n; i++) {
		(*mt)[i] = new int[n];
		//cap phat bo nho cho cac cot 
	}
}

void input(int **mt, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>mt[i][j];
			//Nhap gia tri cua tung phan tu
		}
	}
}

void output(int **mt, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout<<mt[i][j]<<" ";
			//in ra gia tri tung phan tu
		}
		cout<<endl;
	}
}

void free_mem(int **mt, int n) {
	for(int i = 0; i < n; i++) {
		delete [] *(mt + i);
		//giai phong bo nho cua cac hang
	}
	delete [] mt;//giai phong bo nho cac cot
}

int main() {
	//cout<<"To Thai Linh 20215414 - K66 DHBKHN"<<endl;
    int n;//khai bao mot bien n kieu int 

    cin >> n;//nhap gia tri cua n
    
    int **matrix1, **matrix2, **sumMatrix, **productMatrix;
	//khai bao 4 bien con tro cap 2 kieu int
    
    allocate(&matrix1, n);//cap phat bo nho cho matrix1
    allocate(&matrix2, n);//cap phat bo nho cho matrix2
    allocate(&sumMatrix, n);//cap phat bo nho cho sumMatrix
    allocate(&productMatrix, n);//cap phat bo nho cho productMatrix
    
    input(matrix1, n);//nhap gia tri cua matrix1
    input(matrix2, n);//nhap gia tri cua matrix2

	//Tinh tong 2 ma tran
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
	//Tinh tich 2 ma tran
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < n; k++) {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    //cout<<"Ket qua la:"<<endl;
    output(sumMatrix, n);//in ra ma tran tong
    output(productMatrix, n);//in ra ma tran tich
    
    free_mem(matrix1, n);//giai phong ma tran 1
    free_mem(matrix2, n);//giaiphong ma tran 2
    free_mem(sumMatrix, n);//giai phong ma tran tong
    free_mem(productMatrix, n);//giai phong ma tran tich

    return 0;
}//To Thai Linh 20215414

