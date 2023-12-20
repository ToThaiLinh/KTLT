/* To Thai Linh 20215414
Ma lop thuc hanh 7312826*/

#include <iostream>
#include <set>

using namespace std;

template<class T>
//Ham tim hop cua 2 tap hop
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> c = a;//Khai bao mot tap hop c kieu T
    //Gan gia tri cua tap hop a cho c
    c.insert(b.begin(), b.end());
    //Chen them phan tu cua tap hop b cho c
    return c;
}

template<class T>
//Ham tim giao cua 2 tap hop
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;//Khai bao mot tap hop c kieu T
    for(const T &temp : a) {
        //Duyet qua cac phan tu cua tap hop a
        if(b.find(temp) != b.end()) {
            //Neu tim thay no trong b thi gan cho c
            c.insert(temp);
        }
    }
    return c;
}

template<class T>
//Ham in cac phan tu cua mot set
void print_set(const std::set<T> &a) {
     for (const T &x : a) {
         std::cout << x << ' ';
     }
     std::cout << std::endl;
}

int main() {
     std::set<int> a = {1, 2, 3, 5, 7};
     //Khai bao mot tap hop a kieu int
     std::set<int> b = {2, 4, 5, 6, 9};
     //Khai bao mot tap hop b kieu int
     std::set<int> c = set_union(a, b);
     //Gan hop cua 2 tap hop a va b cho set c
     std::set<int> d = set_intersection(a, b);
     //Gan giao cua 2 tap hop cho set d
    
     std::cout << "Union: "; print_set(c);
     //In cac phan tu cua set c
     std::cout << "Intersection: "; print_set(d);
     //In cac phan tu cua set d

     return 0;
}
//To Thai Linh 20215414
