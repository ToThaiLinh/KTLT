/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    //Khai bao mot stack 
    vector<bool> visited(adj.size());
    //Khai bao vector visited luu trang thai cac dinh da tham
    S.push(1); // Bat dau tu dinh 1
    while(!S.empty()) {
    	int u = S.top();
    	//Lay phan tu tren dinh cua stack =
    	if(!visited[u]) {//Kiem tra xem dinh u duoc tham hay chua
    		visited[u] = true;
    		//Danh dau dinh u da duoc tham
    		cout<< u <<endl;
    		//In ra dinh u
    	}
    	if(!adj[u].empty()) {
    		//Kiem tra danh sach cac dinh ke cua u
    		int v = adj[u].front();
    		//Lay dinh dau danh sach
    		adj[u].pop_front();
    		//Xoa dinh do khoi danh sach
    		if(!visited[v]) {
    			//Neu chua tham dinh v thi them vao stack
    			S.push(v);
    		}
    	}
    	//Neu da di den cuoi cua cay
    	else {
    		//Xoa phan tu dau stack
    		S.pop();
    	}
    }
}

int main() {
	int n = 7;//Khai bao so dinh la 7
	vector< list<int> > adj;
	//Khai bao mot vecto chua cac danh sach 
	adj.resize(n + 1);
	//Dat kich thuc cua vector la n + 1
	//Them cac canh ke 
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(7);
	adj[6].push_back(7);
	//Duyet dfs
	dfs(adj);
}
//To Thai Linh 20215414
