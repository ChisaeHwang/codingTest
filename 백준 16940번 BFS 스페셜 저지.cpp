#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[100000];
bool check[100000];

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	vector<int> b(n);
    vector<int> order(n);
    
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i;
    }
    
    for (int i=0; i<n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    
    vector<int> bfs_order;
    queue<int> q;
    q.push(0);
    check[0] = true;
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        bfs_order.push_back(x);
        for (int y : a[x]) {
            if (check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
    
    if (bfs_order == b) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}

//	int m = 1; // 큐의 크기 
//	for(int i=0; i<n; i++){
//		if(q.empty()) // 아직 BFS가 진행 중인데 큐가 비어있음 
//		int x = q.front(); q.pop(); // 앞에 정점 하나 빼기 
//		if(x != order[i]) // 순서가 올바르지 않음 
//		int cnt = 0; // 이번에 큐에 넣어야 할 정점의 수 
//		for(int y : a[x]){ // x와 연결된 모든 y에 대해서 
//			if(checc[y] == false){ // 방문하지 않을 경우 
//				parent[y] = x; // x 는 y를 통해 방문해야함 
//				cnt += 1;
//			}
//		}
//		for(int j=0; j<cnt; j++){
//			// X와 연결되지 않은 정점이 큐에 들어가있으니 올바르지 않음 
//			if(m+j >= n || parent[order[m+j]] != x)
//			q.push(order[m+j]); check[order[m+j]] = true; // q에 넣고, 방문 체크 
//		}
//		m += cnt;
//	}
	
