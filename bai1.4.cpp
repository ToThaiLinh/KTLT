/*To Thai Linh
Ma lop thuc hanh 732826*/

#include <bits/stdc++.h>
using namespace std;
int counteven(int *arr, int size) {
    int count = 0;                      
    //Khoi tao mot bien count kieu int co gia tri bang 0
   
    for(int i = 0; i < size; i++) {     //Duyet qua tat ca cac phan tu cua mang arr
        if(*(arr + i) % 2 == 0) {       
        /*(arr + i) la gia tri cua phan tu thu i trong mang = arr[i]
        Neu *(arr + i) chia het cho 2 thi la so chan */
            count += 1;                 
            //Tang gia tri cua bien count them 1 
        }
    }
    
    return count; //Tra ve gia tri cua bien count
}
//To Thai Linh 20215414

int main() {
	int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
	cout<<counteven(arr, 8);
	return 0;
}
