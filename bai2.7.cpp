/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <iostream>
using namespace std;

template <class T> //Khai bao mot template T
T arr_sum(T a[], int size_a, T b[],int size_b ) {
    //ham tra ve tong 2 mang kieu T 
    T sum = 0;//Khai bao mot bien sum kieu T khoi tao bang 0
    for(int i = 0; i < size_a; i++) {
        sum += a[i];
        //Tinh tong cua cac phan tu trong mang thu nhat luu vao sum
    }
    for(int i = 0; i < size_b;i++) {
        sum += b[i];
        //Tinh tong cac phan tu cua mang 2 roi cong vao sum 
    }
    return sum;
    //Tra ve gia tri sum kieu T 

}

int main() {
    int val;//Khai bao mot bien val kieu int
    cin >> val;//Nhap gia tri cho bien val 
    
    {//Khoi lenh dau tien
        int a[] = {3, 2, 0, val};
        //Khai bao mang a kieu int va gan gia tri cho no 
        int b[] = {5, 6, 1, 2, 7};
        //Khai bao mang b kieu int va gan gia tri cho no
        cout << arr_sum(a, 4, b, 5) << endl;
        //Goi ham arr_sum voi kieu tra ve la int roi in ra man hinh
         
    }
    {//Khoi lenh thu hai
        double a[] = {3.0, 2, 0, val * 1.0};
        //Khai bao mang a kieu double va gan gia tri cho no
        double b[] = {5, 6.1, 1, 2.3, 7};
        //Khai bao mang b kieu double va gan gia tri cho no
        cout << arr_sum(a, 4, b, 5) << endl;
        //Goi ham arr_sum voi kieu tra ve la double roi in ra man hinh
    }

    return 0;
}
//To Thai Linh 20215414
