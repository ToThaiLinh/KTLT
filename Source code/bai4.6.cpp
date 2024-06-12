/* To Thai Linh 20215414
Ma lop thuc hanh: 732826*/
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

void bfs(vector< list<int> > adj) {
    //Khoi tao hang doi luu dinh can duyet
    queue<int> Q;
    //vector danh dau cac dinh da duoc tham 
    vector<bool> visited(adj.size());
    Q.push(1); // Bat dau tu dinh 1
    //Them dinh dau tien vao hang doi 
    while (!Q.empty()) {
        //Lay phan tu o dau hang doi
        int u=Q.front();
        //Neu chua tham thi danh dau da duoc tham va in ra ket qua
        if (!visited[u]){
            visited[u] = true;
            cout<< u << endl;
        }
        //Neu cac dinh ke cua u khong rong
        if (!adj[u].empty()){
            //lay dinh ke dau tien trong danh sach cac dinh ke
            int v = adj[u].front(); 
            //loai bo dinh do khoi danh sach ke 
            adj[u].pop_front();
            //Neu chua duoc tham thi them vao hang doi 
            if (!visited[v]) Q.push(v);
        }
        // Neu khong con dinh ke thi loai bo dinh hien tai ra khoi hang doi
        else Q.pop();
    }
}

int main() {
	int n = 7;
	//Khai bao so dinh la 7
	vector< list<int> > adj;
	//Danh sach ke cua cac dinh
	adj.resize(n + 1);
	//Dat kich thuc cua danh sach bang n + 1
	//Them cac dinh ke 
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(7);
	adj[6].push_back(7);
	bfs(adj);//Goi den ham bfd duyet cay
}
//To Thai Linh 20215414
