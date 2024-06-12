/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>
int main() {
	int a[7] = {13, -355, 235, 47, 67, 943, 1222};
	printf("To Thai Linh 20215414 - K66 DHBK HN\n");
	printf("address of first five elements in memory.\n");
	for(int i = 0; i < 5; i++) {
		printf("\t\ta[%d]          ", i);//In ra cac xau a[i]
	}
	printf("\n");
	for(int i = 0; i < 5; i++) {
		printf("\t%p", &a[i]);//In ra dia chi cua 5 phan tu dau
	}
	printf("\n");
	return 0;
}

