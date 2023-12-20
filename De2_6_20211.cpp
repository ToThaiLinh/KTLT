#include <bits/stdc++.h>
using namespace std;

struct monhoc {
	string maMH;
	int sotinchi;
	int LT;
	int BT;
	int TH;
	monhoc (string ma, int so, int lt, ,int bt, int th): maMH(ma), sotinchi(so), LT(lt), BT(bt), TH(th){
		int sotinchihocphi = lt + bt + th * 1.5;
	}
};

struct hocvien {
	string ma;
	string hoten;
	int somonhoc;
	int sotien;
	int tienhoc1tin;
	int danop;
	int phaidong;
	vector<monhoc> mh;
	hocvien(string mahv, string h, int sm, int st, int t1, int dn, int pd) {
		ma = mahv;
		hoten = h;
		somonhoc = sm;
		sotien = st;
		tienhoc1tin = t1;
		danop = dn;
		phaidong = pd;
	}
};

int main() {
	int sohocvien;
	cout<<"De2_6_IT3040_20211";
	cout<<"\n\nTo Thai Linh - 20215414 - 732826";
	cout<<"\nNhap so sinh vien :"; cin >> sohocvien;
	fflush(stdin);
	monhoc h;
	h.maMH = "1234";
	h.sotinchi = 3;
	h.LT = 1;
	h.BT = 2;
	h.TH = 3;
	cout<<"\n"<<h.tinchihocphi<<endl;
}
