/* To Thai Linh 20215414
Ma lop thuc hanh 732726*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    double result;//Khoi tao bien result luu ket qua
    result=0.5*abs((b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second));
    //Cong thuc tinh dien tich tam giac
    return result;
    //Tra ve ket qua
}

int main() {
    cout << setprecision(2) << fixed;
    //in ra 2 chu so thap phan sau dau phay  
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    //Goi ham tinh dien tich tam giac 
    return 0;
}
//To Thai Linh 20215414
