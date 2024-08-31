#include <bits/stdc++.h>
#define INF 1e9


using namespace std;

int n, m;
int graph[401][401];

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < 401; i++) {
		fill(graph[i], graph[i] + 401, INF);
	}
	
	for(int a = 1; a <= n; a++) {
		for(int b = 1; b <= n; b++) {
			if(a == b) graph[a][b] = 0; // 본인 위치의 가중치는 0 
		}
	}
	
	for(int i = 1; i <= m; i++){ // 간선의 개수만큼 
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	
	for(int k = 1; k <= n; k++) {
		for(int a = 1; a <= n; a++) {
			for(int b = 1; b <= n; b++) {
				if (graph[a][k] != INF && graph[k][b] != INF 
				&& graph[a][b] > graph[a][k] + graph[k][b]) {
    				graph[a][b] = graph[a][k] + graph[k][b];
				}
			}
		}
	}
	int temp = INF;
	
	for(int a = 1; a <= n; a++) {
		for(int b = 1; b <= n; b++) {
			if(graph[a][b] != INF && graph[b][a] != INF && a != b) {
				temp = min(temp, graph[a][b] + graph[b][a]);	
			}
		}
	}
	
	if(temp == INF) cout << -1 << '\n';
	else cout << temp << '\n';
	
	return 0;
}
