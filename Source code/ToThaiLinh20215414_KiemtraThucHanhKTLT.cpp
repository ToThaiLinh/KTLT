#include <bits/stdc++.h> 
using namespace std;

typedef struct dangvien {
	int sothe;
	string ten;
	int ngay, thang, nam;
	string chucvu;
	double luong;
	double tienphucap;
}dangvien;

typedef struct chibo {
	string tenchibo;
	vector<dangvien> dv;
	double tongluong;
	double tongdangphithu;
	double trocapchucvu;
	
}chibo;

int sochibo;
vector<chibo> cb;
double tongluongchibo = 0;
double tongdangphicb = 0;
double tongnopcaptren = 0;

void init() {
	cout<<" To Thai Linh - 20215414 - 732826\n";
	cout<<"**\tCHUONG TRINH QUAN LY Chi bo - Dang Vien **\n";
	cout<<"**1. Nhap cac Chi bo\n";
	cout<<"**2. In ket qua ds Chi bo Dang vien**\n";
	cout<<"**0. Thoat\n";
	cout<<"*******************************************\n";
	cout<<"**\t\tNhap lua chon cua ban\t\t**\n";
	fflush(stdin);	
}

void nhap() {
	string tenchibo;
	int sodangvien;
	cout<<"\nBan da chon nhap ds Chi bo Dang vien!\n";
	for(int i = 0; i < sochibo ;  i++) {
		cout<<"Nhap thong tin Chi Bo thu "<< i + 1<< " :\n\n";
		cout<<"Ten Chi bo: "; getline(cin, tenchibo); fflush(stdin);
		cout<<"\n\nSo dang vien:"; cin >> sodangvien; fflush(stdin);
		cout<<"\n\nNhap ds Dang vien:\n";
		
		double tongluong = 0;
		double tongdangphi = 0;
		double tongtrocap = 0;
		vector<dangvien> d;
		for(int j = 0; j < sodangvien; j++) {
			int sothe;
			string tendangvien;
			int ngay, thang, nam;
			double luong;
			double tienphucap = 0;
			string chucvu;
			cout<<"Dang vien thu "<<j + 1<<"\n";
			cout<<"\tso the:"; cin >> sothe; fflush(stdin);
			cout<<"\n\n\tTen Dang Vien:" ; getline(cin, tendangvien); fflush(stdin);
			cout<<"\n\n\tNgay vao dang:\n";
			cout<<"\tNgay: "; cin >> ngay;fflush(stdin);
			cout<<"\n\n\tThang: "; cin >> thang; fflush(stdin);
			cout<<"\n\n\tNam: "; cin >> nam; fflush(stdin);
			cout<<"\n\n\tLuong: "; cin >> luong; fflush(stdin);
			cout<<"\n\n\tChuc vu:"; cin >> chucvu; fflush(stdin);
			tongluong += luong;
			tongdangphi += (0.01 * luong);
			if(chucvu == "BiThu") {
				tienphucap = luong * 0.05;
			}
			else if(chucvu == "PBThu") {
				tienphucap = luong * 0.03;
			}
			else if(chucvu == "Uyvien") {
				tienphucap = luong * 0.01;
			}
			else if (chucvu == "Dvien" ) {
				tienphucap = 0;
			}
			else {
				tienphucap = 0;
			}
			tongtrocap += tienphucap;
			dangvien v;
			v.sothe = sothe; v.ten = tendangvien; v.ngay = ngay; 
			v.thang = thang; v.nam = nam; v.luong = luong; v.chucvu = chucvu; v.tienphucap= tienphucap;
			d.push_back(v);
		}
		tongluongchibo += tongluong;
		tongdangphicb += tongdangphi;
		tongnopcaptren += tongdangphi * 0.7;
		chibo cbtemp; 
		cbtemp.tenchibo = tenchibo; cbtemp.dv = d; cbtemp.tongluong = tongluong; 
		cbtemp.tongdangphithu = tongdangphi; cbtemp.trocapchucvu = tongtrocap;
		cb.push_back(cbtemp);
	}
	cout<<"\n\nBan da nhap thanh cong!\n To Thai Linh - 20215414 - 732826\n";
}

void in() {
	cout<<"Ban da chon xuat DS Chi Bo, !\n";
	cout<<" To Thai Linh - 20215414 - 732826\n";
	for(int i = 0; i <cb.size(); i ++) {
		cout<<"\n\t\t Ten Chi bo: "<<cb[i].tenchibo;
		cout<<"\n\t\t So Dang vien: "<<cb[i].dv.size();
		cout<<"\n\t\t Tong luong:"<<cb[i].tongluong;
		cout<<"\n\t\t Tong thu Dang phi:"<<cb[i].tongdangphithu;
		cout<<"\n\t\t Tong nop DP Cap tren:"<<cb[i].tongdangphithu * 0.7;
		cout<<"\n\t\t Tong tro Cap chuc vu:"<<cb[i].trocapchucvu;
		cout<<"\n\t\t Bang thu Dang phi:\n";
		cout<<"\t\tsothe\tHotenDv\t\tNgayvaodang\tTuoidang\tChucvu\tTrocap\tLuong\tDangphi\n";
		for(int j = 0; j < cb[i].dv.size(); j++) {
			cout<<"\t\t"<<cb[i].dv[j].sothe<<"\t"<<cb[i].dv[j].ten<<"\t"<<cb[i].dv[j].ngay<<"-"<<cb[i].dv[j].thang<<"-"<<cb[i].dv[j].nam<<"\t"<<
			2023 - cb[i].dv[j].nam<<"\t\t"<<cb[i].dv[j].chucvu<<"\t"<<cb[i].dv[j].tienphucap
			<<"\t"<<cb[i].dv[j].luong<<"\t"<<cb[i].dv[j].luong * 0.01<<"\n";
		}
	}
	cout<<"Tong Luong cac chi bo:"<<tongluongchibo;
	cout<<"\nTong  Dang Phi thu duoc "<<tongdangphicb;
	cout<<"\nTong nop Cap tren: "<<tongnopcaptren<<"\n";
	 
}

void tieptuc() {
	cout<<"\nBam phim bat ky de tiep tuc!";
	cout<<"\nTo Thai Linh - 20215414 - 732826\n";
	char c;
	cin>>c; fflush(stdin);
}

int main() {
	int choice;
    cout<<" Kip 12h30-15h00 Tuan 16 - Ngay 20.12.2023\n";
	cout<<" Kiem tra thuc hanh - Quan Ly Dang Vien\n";
	cout<<" To Thai Linh - 20215414 - 732826\n";
    printf("Nhap so Chi Bo: ");
    scanf("%d", &sochibo);fflush(stdin);
    do {
    	init();
    	scanf("%d", &choice);
    	fflush(stdin);
    	if(choice == 1) {
    		nhap();
    		tieptuc();
    	}
    	else if (choice == 2) {
    		in();
    		tieptuc();
    	}
    }
    while(choice != 0);
}
	


