/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Ham in ket qua
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}
//Ham xoa phan tu chan ra khoi vector
void delete_even(vector<int> &a) {
    vector<int>::iterator it;
    //Khai bao mot con tro it de duyet vector
    for(it = a.begin(); it != a.end(); it++) {
        //Kiem tra gia tri cua it 
        if(*it % 2 == 0) {
            //Neu it la so chan thi xoa phan tu khoi vector
            a.erase(it);
            //Dich con tro ve mot 1 don vi
            it--;
        }
    }
}
//Ham sap xep cac phan tu cua vecto theo thu tu giam dan
void sort_decrease(vector<int> &a) {
    //Su dung ham sort va ham nac danh lamda lam dieu kien so sanh
    sort(a.begin(), a.end(), [] (int a, int b) -> bool {
        return a > b;
    });
}
//Ham gop 2 vector va sap xep theo thu tu giam dan
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    //Khai bao mot vector c
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), greater<int>());
    //Tron 2 vector va chen vao vector c roi sap xep giam dan
    return c;
}

int main() {
    int m, n, u;
    //Khai bao 3 bien m n u kieu int 
    std::vector<int> a, b;
    //Khai bao 2 vector a va b kieu int
    std::cin >> m >> n;//Nhap gia tri m va n
    //Nhap gia tri cho vector a
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    //Nhap gia tri cho vector b
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);//Goi ham xoa phan tu chan ra khoi vector a
    cout << "Odd elements of a: ";
    print_vector(a);//In vector a sau khi xoa phan tu chan

    delete_even(b);//Goi ham xoa phan tu chan ra khoi vector b
    cout << "Odd elements of b: ";
    print_vector(b);//In vector b sau khi xoa phan tu chan 

    sort_decrease(a);//Sap xep vector a
    cout << "Decreasingly sorted a: ";
    print_vector(a);//In vector a

    sort_decrease(b);//Sap xep vector b
    cout << "Decreasingly sorted b: ";
    print_vector(b);//In vector b

    vector<int> c = merge_vectors(a, b);
    //Goi ham tron 2 vector va sap xep
    cout << "Decreasingly sorted c: ";
    print_vector(c);//In vector c

    return 0;
}
//To Thai Linh 20215414
