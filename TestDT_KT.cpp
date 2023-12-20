#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14;

struct Point {
	double x;
	double y;
	double z;
};

struct DuongTron {
	string name;
	Point tam;
	double bankinh;
};

double chuvi(DuongTron a) {
	return 2 * PI * a.bankinh;
}

double dientich(DuongTron b) {
	return b.bankinh * b.bankinh * PI;
}

int main() {
	int soluong;
	vector<DuongTron> listDuongTron;
	Point a, b, c;
	
	while(true) {
		cout<<"\t\t\t To Thai Linh 20215414\n";
		cout<<"\t\tCHUONG TRINH QUAN LY DUONG TRON\n";
		cout<<"1. Nhap danh sach duong tron\n";
		cout<<"2. Nhap toa do 3 diem A, B, C\n";
		cout<<"3. In ra chu vi duong tron\n";
		cout<<"4. In ra dien tich duong tron\n";
		cout<<"5. Toa do trung diem tu tam duong tron den cac diem A, B, C\n";
		cout<<"6. Vi tri tuong doi cua 3 diem A, B, C doi voi duong tron\n";
		cout<<"7. Toa do trong tam G cua tam giac ABC\n";
		cout<<"8. Do dai doan thang IG\n";
		cout<<"0. Thoat chuong trinh\n";
		cout<<"Vui long nhap lua chon cua ban: \n";
		
		int luachon;
		cin>>luachon;
		switch(luachon) {
			case 1 :
				cout<<"\nBan da lua chon nhap danh sach hinh tron!\n ";
				cout<<"Nhap so luong hinh tron: "; cin >> soluong;
				cout<<endl;
				for(int i = 1; i <= soluong; i++) {
					string s;
					double x, y, z, r;
					cout<<"\nNhap ten hinh tron thu "<<i<<" : "; cin >> s;
					cout<<"\n\tNhap toa do tam cua duong tron: x = ";
					cin>>x;
					cout<<"\n\t\t\t\t\t y = ";  cin >> y;
					cout<<"\n\t\t\t\t\t z = "; cin >> z;
					cout<<"\n\t Nhap ban kinh cua duong tron: "; cin >> r; cout<<endl;
					DuongTron c;
					Point d;
					d.x = x; d.y = y; d.z = z;
					c.name = s; c.tam = d; c.bankinh = r; 
					listDuongTron.push_back(c);
				}
				break;
			case 2:
				double x, y, z;
				cout<<"\nBan da lua chon nhap danh sach 3 diem!\n";
				for(int i = 1; i <= 3; i++) {
					cout<<"Nhap toa do diem "<<64 + i<<": x = "; cin >> x;
					cout<<"\n\t\t y = "; cin >> y;
					cout<<"\n\t\t z = "; cin >> z;
				}
				break;
			case 3: 
				cout<<"\nBan da lua chon in ra chu vi duong tron\n";
				cout<<"Chu vi duong tron la: ";
				cout<<chuvi(listDuongTron.front());
			default:
				cout<<"\nBan nhap khong dung. Vui long nhap lai";
				break;			
		}
		
	}
}
