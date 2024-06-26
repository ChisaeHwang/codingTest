#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[20001];
int color[20001]; // 0, 1 : 방문하고 그룹 번호1, 2 : 방문하고 그룹 번호2 

void dfs(int node, int c){ // node 방문, 그룹 번호 : c번 
	color[node] = c; // 방문체크 
	for(int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if(color[next] == 0){ // 아직 방문 안 함 
			dfs(next, 3-c); // 1 -> 2 (3-1), 2 -> 1(3-2) 
		}
	}
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			a[i].clear();
			color[i] = 0;
		}
		
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
		for(int i=1; i<=n; i++){
			if(color[i] == 0){ // 방문여부 체크 
				dfs(i, 1);
			}
		}
		
		bool ok = true;
		for(int i = 1; i <= n; i++){
			for(int k = 0; k < a[i].size(); k++){
				int j = a[i][k];
				if(color[i] == color[j]){ // 겹치는게 있으면 이분그래프가 아님 
					ok = false;
				}
			}
		}

		if(ok){
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} 
	
	return 0;
}
 
