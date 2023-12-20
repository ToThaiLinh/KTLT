/*To Thai Linh 20215414
Ma lop thuc hanh: 732826
Bai 1.9*/
#include <bits/stdc++.h>

void printSolution(int *arr, int size) {
	for(int i  = 0; i < size; i++) {    
	//Duyet tat ca cac phan tu cua day
		for(int j = i; j < size; j++) { 
		//Duyet cac day con cua day
			for(int k = i; k <= j; k++) { 

				printf("%d ", *(arr + k));
				//In ra day con tu i den j 
			}
			printf("\n");
		}
	}
}
int main() {
	//printf("To Thai Linh 2021514 - K66 DHBKHN\n");
	int n;//Khai bao mot bien n kieu int
	int *arr;//Khai bao mot con tro arr kieu int
	
	scanf("%d", &n);//Nhap gia tri cua n
	
	//Cap phat dong bo nho n phan tu kieu int
	arr = new int[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%d", (arr + i));
		//Nhap gia tri cua tung phan tu
	}
	//printf("\nKet qua la:\n");
	printSolution(arr, n);//Goi ham in ra ket qua
	delete [] arr;//Giai phong vung nho duoc cap phat
	return 0;
}
//To Thai Linh 20215414
