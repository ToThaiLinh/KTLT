/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */ 

#include <iostream>
#include <map>

using namespace std;

//ham tim hop cua 2 map
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c = a;
    //Gan map c bang a
    for(const auto &e : b) {
    	//Duyet qua tung phan tu cua map b
    	if(c.count(e.first)) {
    		//Neu khoa trong map a trung voi b
    		c[e.first] = max(c[e.first], e.second);
    		//Gan gia tri max cua a va b cho khoa do
    	}
    	else {
    		//Neu khong tim thay khoa trong map b trung nhau
    		//Them phan tu khac cua map b vao c
    		c.insert(e);
		}
    }
    //Tra ve map c
    return c;
}

//ham tim giao cua 2 map
template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    //Khai bao map c de luu ket qua
    for(const auto &e : a) {
    	//Duyet quy tung phan tu cua map a
    	if(b.find(e.first) != b.end()) {
    		//Neu tim thay phan tu co cung khoa trong map b
    		c[e.first] = min(e.second, b.find(e.first) -> second);
    		//Gan gia tri tai khoa do la min gia tri cua map a va map b tai key co
    	}
    }
    //Tra ve map c
    return c;
}

//Ham in gia tri cua map
template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
	cout << "{ ";
	for (const auto &x : a) {
	 std::cout << "(" << x.first << ", " << x.second << ") ";
	 //In ra gia tri key va value
	}
	cout << "}";
	std::cout << std::endl;
}

int main() {
	std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
	//Khai bao map a co key kieu int va value kieu double 
	std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
	//Khai bao map b co key kieu int va value kieu double
	std::cout << "A = "; print_fuzzy_set(a);//In map a
	std::cout << "B = "; print_fuzzy_set(b);//In map b
	std::map<int, double> c = fuzzy_set_union(a, b);
	//Tinh hop cua 2 map roi luu vao map c
	std::map<int, double> d = fuzzy_set_intersection(a, b);
	//Tinh giao cua 2 map roi luu vao map d
	std::cout << "Union: "; print_fuzzy_set(c);
	//In map c
	std::cout << "Intersection: "; print_fuzzy_set(d);
	//In map d
}
//To Thai Linh 20215414
