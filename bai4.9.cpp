/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct comp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    //Cau truc khai bao hang doi uu tien dung luu tru khoang cach va trong so
    priority_queue<pair<int, int>, vector< pair<int, int> >, comp> q;
    
    //Vector luu tru tu dinh xuat phat den cac dinh con lai
    vector<int> dist(adj.size());
    int dist_size = dist.size();
    //Khai bao bien dist_size de luu tru so luong canh
    //Duyet qua tung canh va gan trong so INT_MAX
    for(int i = 0; i < dist_size; i++){
        dist[i] = INT_MAX;
    }
    //Khoang cach tu dinh xuat phat den chinh no bang 0
    dist[0] = 0; 
    
    // khoi tao gia tri cho hang doi uu tien
    for (int i = 0; i < dist_size; i++){
        q.push({i, dist[i]});
    }
    //Bat dau lap cho den khi q rong
    while (!q.empty()){
    	//Lay ra dinh co thu tu uu tien cao nhat trong hang doi
        pair<int, int> u_pair = q.top(); 
        q.pop();
        //Loai bo dinh do ra khoi hang  doi
        int u = u_pair.first; 
        //khai bao bien u kieu int luu gia tri dinh ke 
        
        //Duyet qua cac dinh ke cua dinh hien tai 
        for (auto v_pair : adj[u]){
            int v = v_pair.first;
            int weight = v_pair.second;
            
            /* Neu khoang cach tu dinh hien tai cong voi trong so canh
			 nho hon khoang cach den dinh v thi cap nhat
			va dua vao hang doi uu tien
			*/ 
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                q.push({v, dist[v]});
            }
        }
    }
   //Tra ve khoang cach tu dinh xuat phat den tat ca cac dinh con lai
    return dist;
}

 int main() {
     int n = 9;
     //Khai bao bien n luu so dinh cua do thi
     vector< vector< pair<int, int> > > adj(n);
     //Khai bao vector luu danh sach ke cua cac dinh
     //Ham them dinh ke voi dinh cho truoc trong do thi vo huong
     auto add_edge = [&adj] (int u, int v, int w) {
     	//Them dinh v ke voi u co trong so w
		adj[u].push_back({v, w});
		//Them dinh u ke voi v co trong so w
		adj[v].push_back({u, w});
     };
     //Gan danh sach cac dinh
     add_edge(0, 1, 4);
     add_edge(0, 7, 8);
     add_edge(1, 7, 11);
     add_edge(1, 2, 8);
     add_edge(2, 3, 7);
     add_edge(2, 8, 2);
     add_edge(3, 4, 9);
     add_edge(3, 5, 14);
     add_edge(4, 5, 10);
     add_edge(5, 6, 2);
     add_edge(6, 7, 1);
     add_edge(6, 8, 6);
     add_edge(7, 8, 7);

     vector<int> distance = dijkstra(adj);
     //Khai bao mot vector khoang cach tu dinh 0 den cac dinh con lai
     //In khoang cach tu dinh 0 den cac dinh con lai
     for (int i = 0; i < distance.size(); ++i) {
         cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
     }
     return 0;
}
//To Thai Linh 20215414
