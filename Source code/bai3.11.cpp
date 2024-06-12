/*To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int n, r;//Khai bao bien toan cuc n va r kieu int
int price[MAX][MAX];//Ma tran chi phi
int x[MAX];//Luu hanh trinh tot nhat
bool visited[MAX];//Bien danh dau da tham 
vector<int> vt;//Luu hanh trinh 
int best, sum_price, start, des, numOfPoint;
vector<int> result; //Vector luu ket qua

//Ham nhap du lieu dau vao
void inputData(){
    cin >> n >> r;//Nhap gia tri n va r
    //Nhap ma tran chi phi
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> price[i][j];
        }
    }
}

//Ham kiem tra nguoi a co the di den i hay khong
bool check(int a, int i){
	//Neu da tham tra ve false
    if(visited[vt[i]]) return false; 
    //Neu chi phi = 0 tra ve false
    if(price[x[a-1]][vt[i]] == 0) return false;
    return true;
}

//Ham tinh gia tri tot nhat
void solution(){
	//Neu khong co chi phi di den diem ket thuc thi tra ve
    if (price[x[numOfPoint-2]][des] == 0) return;
    //Chi phi tot nhat la gia tri nho nhat cua cac chi phi
    best = min(best, sum_price + price[x[numOfPoint-2]][des]);
}

void TRY(int k){
	//Ham kiem tra lich trinh di chuyen
    for (int i = 1; i < numOfPoint - 1; i++){
        if (check(k, i)){
        	//Danh dau diem da tham 
            visited[vt[i]] = true;
            //Tinh tong chi phi
            sum_price += price[x[k-1]][vt[i]];
            //Cap nhat duong di tot nhat
            x[k] = vt[i];
            
            //Neu di den diem gan cuoi thi tinh gia tri tot nhat
            if (k == numOfPoint - 2) solution();
            //De quy
            else TRY(k+1);
            //Quay lui
            visited[vt[i]] = false;
            sum_price -= price[x[k-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    inputData(); //Goi ham nhap du lieu
    getline(cin,str);//Doc mot dong tu dau vao gan cho str

    while(r > 0){
    	//Vong lap tuong ung voi so nguoi trong doan
        best = INT_MAX;
        //Khoi chi phi nho nhat la INT_MAX
        sum_price = 0;//Khoi tao tong chi phi
        getline(cin, str);
        while (!str.empty()){
        	//Chay vong lap cho den khi het ky tu
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);
            //Them gia tri vao vector de luu danh sach diem yeu cau

            if (str.find(" ") > str.size()) break;
            //Kiem tra neu khong con khoang trang thi thoat
            else str.erase(0, str.find(" ") + 1);
            //Xoa phan tu chuyen doi tu str
        }
        //Khoi tao diem bat dau la phan tu dau tien trong danh sach
        start = vt[0];
        //Diem den la phan tu cuoi cung
        des = vt[vt.size() - 1];
        //So diem can di la kich thuoc cua vector
        numOfPoint = vt.size(); 
        x[0] = start; x[numOfPoint-1] = des;
        //Ham khoi tao bien tham cac dinh bang false
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
        //De quy bat dau tu phan tu dau tien
        TRY(1);
        //Neu gia tri tot nhat khong thay doi thi in ra 0
        if (best == INT_MAX) result.push_back(0);
        else result.push_back(best); 
        //Them vao day ket qua
        
        //Xoa vector
        vt.erase(vt.begin(), vt.end());
        r--;//Duyet den nguoi tiep theo
    }
    //In day ket qua
    for(int i : result) {
    	cout<<i<<endl;
    }
}
//To Thai Linh 20215414



