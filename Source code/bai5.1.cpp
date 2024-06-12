/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n");//Sua ham print("\n") thanh printf("\n")
}

void process(int i) {
    if (i > n){
        print();//Sua ham printf() thanh print()
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}
//To Thai Linh 20215414

