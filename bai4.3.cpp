/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <tuple>

using namespace std;
using Vector = tuple<double, double, double>;
//Dat ten cho kieu du lieu tuple la Vector

//Ham tinh tich co huong cua 2 vector trong khong gian 3 chieu
Vector cross_product(Vector a, Vector b) {
    return Vector(
        std::get<1>(a) * std::get<2>(b) - std::get<2>(a) * std::get<1>(b),
        std::get<0>(b) * std::get<2>(a) - std::get<0>(a) * std::get<2>(b),
        std::get<0>(a) * std::get<1>(b) - std::get<1>(a) * std::get<0>(b)
    );
    //Tra ve vector tich vo huong cua 2 vector a va b
}

int main() {
	cout << setprecision(2) << fixed;
	//In ra 2 chu so thap phan sau dau phay
	Vector a {1.2, 4, -0.5};
	//Khai bao mot tuple a 
	Vector b {1.5, -2, 2.5};
	//Khai bao mot tuple b
	Vector c = cross_product(a, b);
	//Tinh tich co huong cua a va b
	cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
	//In ket qua
	return 0;
}
//To Thai Linh 20215414
