/*To  Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int key, value;
	//Khai bao 2 gia tri key va value kieu int
	vector< pair<int, int> > element;
	//Khai bao vector element chua 2 gia tri int de luu dau vao
	while(cin >> key >> value) {
		//Nhap gia tri den khi khong con dau vao
		element.push_back(make_pair(key, value));
	}
	/*Ham sort su dung ham nac danh lamda voi bieu thuc dieu kien 
	la cap gia tri key va value
	Neu value khac nhau thi sap xep giam dan
	con giong nhau thi sap xep giam dan theo key*/
	sort(element.begin(), element.end(),
	 [](const pair<int, int> & a, const pair<int, int> & b) -> bool {
		if(a.second != b.second) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	});
	//In cac phan tu cua element khi da sap xep
	for(auto it : element) {
		cout<<it.first<<" "<< it.second <<endl;
	}
	return 0;
}
//To Thai Linh 20215414
