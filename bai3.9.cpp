/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 210;

int N, K1, K2, counter = 0;
int a[MAX], sum = 0, dau = -1;

void TRY(int k) {
	//Ham thu tat ca cac kha nang cua ngay thu k
	if(k > N) {
		//Duyet qua tat ca N ngay thi in ket qua
		for(int i = 1; i <= N; i++) {
			if(sum < K1 && sum > 0) return;
			cout<<a[i];
			//In ra lich lam viec
		}
		counter++;
		cout<<endl;
		return;
	}
	if(dau == -1) {
		//Kiem tra xu ly ngay dau tien
		//Truong hop ngay dau tien la nghi lam
		a[k] = 0;
		dau = 0;
		//Goi de quy ngay tiep theo
		TRY(k + 1);
		
		//Truong hop ngay dau tien di lam 
		a[k] = 1;
		dau = 1;
		sum = 1;
		//Goi de quy ngay tiep theo
		TRY(k + 1);
		exit(0);
	}
	//Luu gia tri cua sum vao old_S de quay lui
	int old_S = sum;
	//Luu gia tri cua dau vao old_D de quay lui
	int old_D = dau;
	
	if(old_D == 0) {
		//Neu phan tu dung truoc bang 0
		a[k] = 1;//Gan phan tu hien tai bang 1
		sum = 1;
		dau = 1;
		//De quy voi phan tu tiep theo
		TRY(k + 1);
		
		//Quay lui
		sum = old_S;
		dau = old_D;
	}
	//Neu ngay truoc do la ngay di lam
	//hay phan tu truoc do la 1 
	else {
		//Neu tong so ngay lam viec nho hon K2
		if(old_S < K2) {
			//Tong so ngay lam viec lon hon hoac bang K1
			if(old_S >= K1) {
				//Gan ngay tiep theo la ngay nghi
				a[k] = 0;
				dau = 0;
				sum = 0;
				TRY(k + 1);
				sum = old_S;
				dau = old_D;
			}
			//Truong hop ngay tiep theo la ngay di lam 
			a[k] = 1;
			dau = 1;
			sum += 1;
			TRY(k + 1);//De quy
			sum = old_S;//Quay lui
			dau = old_D;
		}
		else {
			//Xu ly tong ngay lam viec khong lon hon K2
			a[k] = 0;
			dau = 0;
			sum = 0;
			//De quy
			TRY(k + 1);
			//Quay lui
			sum = old_S;
			dau = old_D;
		}
	}
}

int main(int argc, char** argv) {
	//Nhap vao gia tri N, K1, K2
	cin>>N>>K1>>K2;
	//Bat dau thu voi ngay dau tien
	TRY(1);
	cout<<counter<<endl;
	return 0;
}
//To Thai Linh 20215414

