/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/

#include <bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;
    
    for(int i = l; i <= r/2; i++) { //Duyet tat ca các phan tu cua mang
        tmp = arr[i];          //Gan giá tri cua arr[i] cho tmp
        arr[i] = arr[r - i];  //Gan giá tri cua arr[r - i] cho ar[i]
        arr[r - i] = tmp;    //Gan giá tri cua tmp cho arr[r - i]
    }
    
}

void ptr_reversearray(int *arr, int size){

    int l = 0, r = size - 1, tmp;
    
    for(int i = l; i <= r/2; i++) {  //Duyet tat ca các phan tu cua mang
        tmp = *(arr + i);            //Gán giá tr? c?a arr[i] cho tmp
        *(arr + i) = *(arr + r - i);//Gan giá tri cua arr[r - i] cho ar[i]
        *(arr + r - i) = tmp;       //Gan giá tri cua tmp cho arr[r - i]
    }
}
//To Thai Linh 20215414

int main() {
	int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	int arr2[] = {4, -1, 5, 9};
		ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
}

