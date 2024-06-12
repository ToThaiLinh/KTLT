/* To Thai Linh 20215414
Ma lop thuc hanh 732826 */

#include <bits/stdc++.h>

using namespace std;

struct data {
	int ai;//So quan dich tan cong tuong i
	int ki;//So dich moi linh co the day lui khoi tuong i
	
	//ham khoi tao gia tri cho data
	data(int ai, int ki) {
		this -> ai = ai;
		this -> ki = ki;
	}
}; 

//Dinh nghia toan tu so sanh cho cap gia tri data
struct comp {
	bool operator() (data a, data b) {
		int ra, rb;
		
		//Tinh toan gia tri dau ra cho doi tuong a
		if(a.ai <= a.ki) ra = a.ai;
		else ra = a.ki;
	
		//Tinh toan gia tri dau ra cho doi tuong b
		if(b.ai <= b.ki) rb = b.ai;
		else rb = b.ki;
		
		return ra < rb;
	}
};

//So luong tuong n, so linh s, so dich bi tieu diet va tong dich
int n, s, kill_enemy, total_enemy;
priority_queue<data, vector<data>, comp> Q;

//Ham nhan du lieu dau vao tu nguoi dung
void inputData() {
	//Nhap so tuong va tong so linh
	cin>>n>>s;
	//Khoi tao so dich bi tieu dich bang 0
	kill_enemy = 0;
	//Khoi tao tong so quan dich bang 0
	total_enemy = 0;
	for(int i = 0; i < n; i++) {
		//Khoi tao 2 bien luu so quan dich
		//va kha nang day lui cua moi linh
		int tmp1, tmp2;
		cin>>tmp1>>tmp2;
		//tinh tong so quan dich
		total_enemy += tmp1;
		//Them du lieu vao hang doi uu tien
		Q.push(data(tmp1, tmp2));
	}
}

//Ham thuc hien ham phan phoi linh sao cho tong so linh s
//tong so dich lot vao lau dai la nho nhat
void solve() {
	//vong lap kiem tra dam bao hang doi uu tien khong trong
	//dam bao con linh de phan bo
	while(!Q.empty() && s > 0) {
		//Lay tuong uu tien nhat trong hang doi uu tien
		data inf = Q.top();
		//loai bo phan tu do
		Q.pop();
		
		//Tinh toan so quan dich bi tieu diet
		if(inf.ai <= inf.ki) kill_enemy += inf.ai;
		else {
			int nenemy = inf.ai - inf.ki;
			//them nhung dich chua bi tieu diet vao hang doi uu tien de don quan
			Q.push(data(nenemy, inf.ki));
			kill_enemy += inf.ki;
		}
		//Giam so linh di 1
		s -= 1;
	}
}

//ham tra ve so dich con lai 
int calc_enemy() {
	return total_enemy - kill_enemy;
}

int main() {
	inputData();//goi ham nhap du lieu tu nguoi dung
	solve();//Sap xep quan 
	cout<<calc_enemy();//tinh toan so dich lot vao
	return 0;
}
//To Thai Linh 20215414

