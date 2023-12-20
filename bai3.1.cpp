/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <stdio.h>
int lucas(int n) {
    //Truong hop co ban de ket thuc de quy
    if(n == 0) return 2;
    else if(n == 1) return 1;
    //Truong hop de quy
    else return lucas(n - 1) + lucas(n - 2);
}

int main() {
	for(int n = 0; n <= 10; ++n) {
		printf("L[%d] = %d\n", n, lucas(n));
	}
	return 0;
}
//To Thai Linh 20215414
