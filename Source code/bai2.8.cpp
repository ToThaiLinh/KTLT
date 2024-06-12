/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    int val1, val2;
    //Khai bao 2 bien kieu int 
    cin >> val1 >> val2;
    //Nhap gia tri cho 2 bien
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    //Khai bao mang vector bao gom cac phan tu la vector
    sort(a.begin(), a.end(), [] (const vector<int> &p, const vector<int> &q) -> bool
    {
        return accumulate(p.begin(), p.end(), 0) > accumulate(q.begin(), q.end(), 0);
    });
    /*Sap xep cac vector trong a theo tong giam vector giam dan 
    Su dung cu phap lamda bang cach nhan doi so la 2 vector va dung ham accumulate 
    de tinh tong cac phan tu trong mang*/
    for (const auto &v : a) {
        //Duyet qua tung vector cua mang cac vector a
        for (int it : v) {
            //Duyet qua tung phan tu cua vector
            cout << it <<' ';
            //In gia tri tung phan tu cua vector
        }
        cout << endl;
    }
    return 0;
}
//To Thai Linh 20215414
