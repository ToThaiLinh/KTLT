/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/

#include <bits/stdc++.h>

using namespace std;

//Khai bao 2 bien w va h kieu int de lua chieu dai va chieu rong 
int w, h;
//mang 2 chieu table de luu dien tich moi phan cua hinh chu nhat
int table[601][601];

//ham khoi tao gan gia tri cho table la dien tich khi biet chieu cao va chieu rong
void init() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            table[i][j] = i*j;
        }
    }
}

int main()
{
	//Tat dong bo hoa voi stdio de tang toc do 
    ios::sync_with_stdio(false);
    cin.tie();//Tranh truong hop dong bo hoa tu dong

    int m;//Khai bao bien m kieu int luu so luong hcn se bi loai bo
    cin >> w >> h;//Nhap gia tri chieu dai va chieu rong
    cin >> m;//Nhap so luong hinh chu nhat bi loai bo 
    init();//Khoi tao bang luu dien tich
    //Nhap toa do chieu rong chieu dai cua cac hinh chu nhat bi cat
    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }

	//Su dung quy hoach dong tinh gia tri toi uu cho moi o trong bang table
    //dp
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            int minWaste = table[i][j];
            // horizonal cut
            for(int k=1; k<=i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i-k][j]);
            }
            // vertical cut
            for (int k=1; k<=j; k++) {
                minWaste = min(minWaste, table[i][k] + table[i][j-k]);
            }
            table[i][j] = minWaste;
        }
    }
	//In gia tri toi uu
    cout << table[h][w] << endl;
}
//To Thai Linh 20215414;
