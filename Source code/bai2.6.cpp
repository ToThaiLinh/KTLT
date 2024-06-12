/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>

void print(int n) {
    //ham in gia tri cua n
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    //Ham tra ve kieu int gia tri n * 3 + 1
    return n * 3 + 1;
}

int div2(int n) {
    //Ham tra ve gia tri kieu int co gia tri n / 2
    return n / 2;
}

// khai báo các tham s? cho các con tr? hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int) ) {
    /*Ham mo phong qua trinh bien doi de kiem dinh gia thuyet voi 
    doi so la so nguyen n, 3 con tro ham*/
    (*output)(n);//Goi den ham ma output tro den 
    if (n == 1) return;
    //Neu n = 1 thi dung lai
    if (n % 2 == 0) {
        //Neu n la so chan goi den ham ma even tro den
        n = (*even)(n);
    } else {
        //Neu n la so le goi den ham ma odd tro den
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
    //Goi de quy ham simulate
}

int main() {
    int (*odd)(int) = NULL;
    //Khai bao mot con tro ham odd tro den NULL
    int (*even)(int) = NULL;
    //Khai bao mot con tro even tro den NULL

    odd = mul3plus1;//Gan dia chi cua ham mul3plus1 cho con tro odd
    even = div2;//Gan dia chi cua ham div2 cho con tro even 

    int n;//Khai bao mot bien n kieu int 
    scanf("%d", &n);//Nhap gia tri cua n
    simulate(n, odd, even, print);
    /*Goi den ham simulate voi doi so truyen vao la 
    gia tri n, dia chi cac ham ung voi odd, even, print*/

    return 0;
}
//To Thai Linh 20215414
