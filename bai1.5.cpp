/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/

#include<bits/stdc++.h>

double* maximum(double* a, int size){

    double *max;//Khai bao mot con tro max kieu double
    max = a;    //Gan dia chi dau cua mang a cho max
    
    if (a==NULL) return NULL; //Neu dia chi cua a NULL thi tra ve NULL
    
    for(int i = 0; i < size; i++) { //Duyet tung phan tu c?a mang
        if(*(a + i) > *max) {  
        //Neu gia tri cua a[i] > gia tri cua dia chi con tro max tro toi
            max = a + i;//Gan dia chi cua gia tri do cho con tro max
        }
    }
    
     return max;//Tra lai dia chi con tro max tro toi 
}
//To Thai Linh 20215414

int main() {
	double arr[] = {1., 10., 2., -7., 25., 3.};
	double* max = maximum(arr, 6);
	printf("%.0f", *max);
	return 0;
}
