#include <bits/stdc++.h>
#define MAX 17

using namespace std;

int parent[100001][17]; 
int depth[100001];
vector<vector<int>> adj;  //adjacency
int n, m;

void dfs(int cur) {
	for(int next : adj[cur]) {
		if(depth[next] == -1) { // ���� �� ���� ��� 
			depth[next] = depth[cur] + 1; // ���� ���� 
			parent[next][0] = cur; // �ٷ� ���� �θ� ��� ���� 
			dfs(next);
		}
	}
	
	return;
}

void connection() {
	
	for(int k = 1; k < 17; k++) { // �ٷ� ���� �θ�� �̹� ������ �����̹Ƿ� 1���� ���� 
		for(int cur = 1; cur <= n; cur++) { // ���� 1 ~ n���� 
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
	
	return;
}

int LCA(int u, int v) {
	
	if(depth[u] < depth[v]) {
		swap(u, v);
	}
	
	int diff = depth[u] - depth[v];
	
	for(int i = 0; diff != 0; i++) { // ���� ���� 
		if(diff % 2 == 1) {
			u = parent[u][i];
		}
		
		diff /= 2; 
	}
	
	if (u != v) {
		for(int i = MAX - 1; i >= 0; i--) {
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
			
			u = parent[u][0];
		}
	}
	
	return u;
	
}

int main() {
	
	cin >> n;
	adj.resize(n + 1);
	fill(depth, depth + n + 1, -1); // �׳� �迭 �ʱ�ȭ 
	memset(parent, -1, sizeof(parent)); // 2���� �迭 �ʱ�ȭ 
	
	depth[1] = 0;
	
	for(int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	dfs(1);
	connection();
	
	cin >> m; 
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
	
	return 0;
} 
