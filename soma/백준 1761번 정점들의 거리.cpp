#include <bits/stdc++.h>

using namespace std;

const int MAX_DEPTH = 21;
int parent[40001][21]; 
int depth[40001];
int dist[40001];
vector<vector<pair<int, int>>> adj;  //adjacency
int n, m, k;

void dfs(int cur) {
	
	for(auto& p : adj[cur]) { // 주소값을 가져오는게 더 효율 좋음(속도, 수정) 
		int next = p.first;
		int cost = p.second;
	    
		if(depth[next] == -1) { // 갱신 안 했을 경우 
			depth[next] = depth[cur] + 1; // 깊이 갱신 
			parent[next][0] = cur; // 바로 위에 부모 노드 갱신 
			dist[next] = dist[cur] + cost;
			dfs(next);
		}
	}
	
	return;
}

void connection() {
	
    for (int k = 1; k < MAX_DEPTH; k++) { // 바로 위에 부모는 이미 갱신한 상태이므로 1부터 시작
        for (int cur = 1; cur <= n; cur++) { // 노드는 1 ~ n까지
            parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
}


int LCA(int u, int v) {
	
	if(depth[u] < depth[v]) {
		swap(u, v);
	}
	
	int diff = depth[u] - depth[v];
	
	for(int i = 0;  diff != 0; i++) { // 깊이 조절 
		if(diff % 2 == 1) {
			u = parent[u][i];
		}
		
		diff /= 2; 
	}
	
	if (u != v) {
		for(int i = MAX_DEPTH - 1; i >= 0; i--) {
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		
		u = parent[u][0];
	}
	
	return u;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);

		cin >> n;
		adj.resize(n + 1);
		fill(depth, depth + n + 1, -1); // 그냥 배열 초기화 
		fill(dist, dist + n + 1, 0); // 거리 배열 초기화 
		memset(parent, -1, sizeof(parent)); // 2차원 배열 초기화 
		
		depth[1] = 0;
		
		for(int i = 0; i < n - 1; i++) {
			int from, to, cost; 
			cin >> from >> to >> cost;
			adj[from].push_back({to, cost});
			adj[to].push_back({from, cost});
		}
		
		dfs(1);
		connection();
		
		cin >> m; 
		
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			cout << dist[u] + dist[v] - (dist[LCA(u, v)] * 2) << '\n';
		} 
	
		
	return 0;
} 
