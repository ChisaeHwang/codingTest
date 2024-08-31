#include <bits/stdc++.h>

using namespace std;

vector<int> a[1001];
bool check[1001]; 
void dfs(int node){
	check[node] = true;
	for(int i = 0; i < a[node].size(); i++){
		int next = a[node][i];
		if(check[next] == false){
			dfs(next);
		}
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;
	
	// 인접 리스트 생성 
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	
	// 각 시작점에 대해 방문한 적이 없으면 DFS 실행 
	int components = 0;
	for(int i=1; i<=n; i++){
		if(check[i] == false){
			dfs(i);
			components += 1; // DFS 가 실행되면 새로운 연결 요소가 필요하므로 1 츠가 
		}
	}
	
	cout << components << '\n';
	
	 
	return 0;
}
