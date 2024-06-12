/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include<bits/stdc++.h>
using namespace std;

const int N = 10000;

//Cac vector string chua tai lieu
vector<string> doc[N]; 
//Tan so xuat hien cua tu
map<string, int> f[N]; 
//So luong tai lieu ma moi tu xuat hien
map<string, int> df; 
//Tan so xuat hien lon nhat va so luong tai lieu
int maxf[N], n;

//Hàm tính Term Frequency
double TF(string t, int d){
	//Neu tan so xuat hien cua tu t trong tai lieu d = 0 thi return 0
	//Nguoc lai tra ve gia tri TF theo cong thuc
	if (f[d][t] == 0) return 0;
	return 0.5 + 0.5 * f[d][t] / maxf[d];
}

//Ham tinh gia tri Inverse Document Frequence
double IDF(string t){
	//Tra ve gia tri IDF theo cong thuc
	return log2(1.0 * n / df[t]);
}

//Ham tinh diem tuong tu cua t trong tai lieu d
double score(string t, int d){
	//Neu t khong xuat hien trong tai lieu nao tra ve 0
	//Nguoc lai thi tinh gia tri diem tuong tu
	if (df.count(t) == 0) return 0;
	return TF(t, d) * IDF(t);
}

int main(){
	//So luong tai lieu
	cin >> n;
	for (int i = 0; i < n; i++){
		//Chuoi t chua noi dung dau vao
		string t;
		cin >> t;//Nhap chuoi t
		string w;
		//tao map luu tru tan so xuat hien cua tung tu trong tai lieu
		map<string, int> d_f;

		//Duyet cac ky tu cua chuoi t
		for (char c : t){
			//Neu no khong phai dau phay, them vao tung ky tu de tao thanh tu w
            if (c != ',') w.push_back(c);
			else {
				//Nguoc lai thi tang tan so xuat hien trong tai lieu
                d_f[w]++;
                if(d_f[w] == 1) df[w]++;
				//Them tu vao vector doc[i]
				doc[i].push_back(w);
				f[i][w]++;
				//Dat w la rong
				w = "";
				continue;
			}
		}
		d_f[w]++;
        if (d_f[w] == 1) df[w]++;
		doc[i].push_back(w);
		f[i][w]++;

		//Duyet cac gia tri key-value cua map tan so
		for (auto it : f[i]){
			//Tang tan so xuat hien lon nhat
			maxf[i] = max(maxf[i], it.second);
		}
	}

	//So luong cau truy van
	int q;
	cin >> q;
	while (q--){
		//tao vector luu tru cac cau truy van
		vector<string> query;
		//Chua noi dung cua tung cau truy van
		string t;
		cin >> t;
		string w;

		//Duyet qua cac ky tu cua tung cau truy van
		for (char c : t){
			//Neu ky tu khong phai dau phay thi them tung ky tu de tao thanh tu w
			if(c != ',') w.push_back(c);
			//Nguoc lai thi them w vao hang doi va dat w ve rong de xu ly tu sau
			else{
				query.push_back(w);
				w = "";
				continue;
			}
		}

		//Them w vao hang doi
		query.push_back(w);
		//Lay gia tri tempscope la am vo cung
		double tempscore = -1e9;
		//So thu tu cua tai lieu co diem tuong tu cao nhat
		int document = 0;
		//So thu tu cua tai lieu dang xet
		int d = 0;
		while (d < n){
            double totalscore = 0;

			for(string t : query){
				totalscore += score(t, d);
			}
			d++;

			//Thoa man dieu kien duoi thi cap nhat tempscope va document
			if (totalscore > tempscore){
				tempscore = totalscore;
				document = d;
			}
		}
		//In ra gia tri cua documet
		cout << document << endl;
	}
}
//To Thai Linh 20215414


