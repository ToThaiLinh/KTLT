#include <bits/stdc++.h>
using namespace std;

const int SO_CHI_BO = 2;

struct dangvien {
	int sothedv;
	string tendangvien;
	int ngay, thang, nam;
	string chucvu;
	double luong;
	double dangphi;
	double tientrocap;
	int phaidong;
	
	dangvien(int sothe, string ten, int ngay_input, int thang_input, int nam_input, double lg,double dp, double tienphucap, string cvu, double dong = 0) {
		sothedv = sothe;
		tendangvien = ten;
		ngay = ngay_input;
		thang = thang_input;
		nam = nam_input;
		luong = lg;
		dangphi = dp;
		chucvu = cvu;
		tientrocap = tienphucap;
		phaidong = dong;
	}
};

struct chibo {
	string tencb;
	string diachi;
	vector<dangvien> dv;
	int tongluong;
	int tongdangphithu;
};

double trocap(vector<dangvien> dv){
	double sum = 0;
	for(int i = 0; i < dv.size(); i++) {
		sum += dv[i].tientrocap;
	}
	return sum;
}

int main() {
	vector<chibo> ChiBo(SO_CHI_BO);
	while(true) {
		cout<<"De4_8_IT3040_20221"<<endl;
		cout<<"To Thai Linh - 20215414 - Ma lop Th : 732826"<<endl;
		cout<<"**\t CHUONG TRINH QUAN LY Chi bo - Dang Vien **\n";
		cout<<"**1. Nhap cac Chi bo\t\t**\n";
		cout<<"**2. In ket qua ds Chi bo Dang vien**\n";
		cout<<"**0. Thoat                       **\n";
		cout<<"*******************************************\n";
		cout<<"**     Nhap lua chon cua ban             **\n";
		
		int luachon; cin >> luachon;
		cout<<endl;
		switch(luachon) {
			case 1:
				cout<<"Ban da lua chon nhap ds Chi bo Dang Vien!"<<endl;
				for(int i = 1; i <= SO_CHI_BO; i++) {
					string name;
					int sodangvien;
					double tongluong = 0;
					double tongdangphithu = 0;
					cout<<"Nhap thong tin Chi bo thu "<<i<<" :"<<endl;
					cout<<"\t Ten Chi bo: " ; cin >> name;
					cout<<"\n\n\t So dang vien: "; cin >> sodangvien;
					cout<<"\n\n\t Nhap ds Dang vien:\n";
					vector<dangvien> DV;
					for(int j = 1; j <= sodangvien; j++) {
						int sothe;
						string tendangvien;
						int ngay, thang, nam;
						double luong;
						double dangphi;
						string chucvu;
						cout<<"\tDang vien thu "<<j<<endl;
						cout<<"\n\t\tso the:";cin >> sothe; fflush(stdin);
						cout<<"\n\n\t\tTen dang vien:"; getline(cin, tendangvien);
						cout<<"\n\n\t\tNgay vao dang:\n";
						cout<<"\t\tNgay:"; cin >> ngay;
						cout<<"\n\t\tThang:"; cin >> thang;
						cout<<"\n\t\tNam:"; cin >> nam;
						cout<<"\n\n\t\tLuong:"; cin >> luong;
						cout<<"\n\n\t\tChuc vu:"; cin >> chucvu;
						cout<<"\n\n";
						dangphi = 0.01 * luong;
						tongluong += luong;
						tongdangphithu += dangphi;
						double tienphucap = 0;
						if(chucvu == "BiThu") {
							tienphucap = 0.005 * luong;
						}
								
						else if (chucvu =="Pbthu"){
							tienphucap = 0.0025 * luong;
						}			
						else if(chucvu =="Uyvien") {
							tienphucap = 0.0015 * luong;
						}
								
						else if(chucvu == "DVien") {
							tienphucap = 0;
						}
						dangvien v = dangvien(sothe, tendangvien, ngay, thang, nam, luong,dangphi, tienphucap, chucvu);
						DV.push_back(v);
					}
					chibo c;
					c.tencb = name;
					c.dv = DV;
					c.tongluong = tongluong;
					ChiBo.push_back(c);
				}
				cout<<"Ban da nhap thanh cong!\n";
				break;
			}
			break;
		}
	}
