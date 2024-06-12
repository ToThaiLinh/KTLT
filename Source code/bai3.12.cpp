/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/

#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

int n, k;//n la so dinh, k la so canh di qua
int m;// m la so canh cua do thi
vector<vector<int> > vt; //Vector ma tran ke cua do thi
int x[MAX];//Luu duong di 
bool visited[MAX];//Bien danh dau tham canh
int cnt;//Bien dem so cach di 

//Ham nhap gia tri dau vao
void inputData(){
	//Nhap gia tri cho n , k , m
    cin >> n >> k;
    cin >> m;
    //Dat kich thuoc cua vector la n + 1
    vt.resize(n+1);
    //Nhap vao gia tri cac canh cua do thi 
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vt[u-1].push_back(v-1);
		//them v - 1 vao danh sach canh ke cua u - 1 
        vt[v-1].push_back(u-1);
		// them u - 1 vao danh sach canh ke cua v - 1
    }
    //Khoi tao cac bien tham la false
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    //Khoi tao gia tri so luong duong di la 0
    cnt = 0;
}

bool check(int a, int i){
	//a la vi tri dang xet trong mang
	//i la dinh duoc chon de dat tai a
    if (a == 0) return true;
    //Neu la dinh dau tien thi no la true
    if (visited[i]) return false;
    //Kiem tra dinh i, neu da tham tra ve false

    int index = 0;
    for (int j = 0; j < vt[x[a-1]].size(); j++){
    	//Duyet qua cac dinh ke voi a
        if (i == vt[x[a-1]][j]) index++;
        //Neu i thuoc dinh ke cua a thi tang index len 1
    }
    //Khong co dinh ke tra ve false
    if (index == 0) return false;
    return true;
}

//Ham tinh toan so luong duong di
void solution(){
    cnt++;
}

void TRY(int a){
	//Ham kiem tra cac gia tri co the gan cho vi tri a
    for (int i = 0; i < n; i++){
    	//Duyet qua cac dinh cua do thi
        if (check(a, i)){
        	//Kiem tra dinh i co the gan cho vi tri a hay khong
            visited[i] = true;
            //Danh dau la da tham
            x[a] = i;//Gan i cho x[a]
            
            //Neu da duyet het k canh thi tang bien dem
            if(a == k) solution();
            else TRY(a+1);//De quy
            //Quay lui
            visited[i] = false;
        }
    }
}

int main(int argc, const char** argv) {
    inputData();//Goi ham nhap gia tri
    TRY(0);//Bat dau voi dinh 0
    cout << cnt/2; // In ket qua
}
//To Thai Linh 20215414


 
