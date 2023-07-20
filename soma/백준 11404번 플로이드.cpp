#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}
	
	for(int a = 1; a <= n; a++) {
		for(int b = 1; b <= n; b++) {
			if(a == b) graph[a][b] = 0; // 본인 위치의 가중치는 0 
		}
	}
	
	for(int i = 1; i <= m; i++){ // 간선의 개수만큼 
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	
	for(int k = 1; k <= n; k++) {
		for(int a = 1; a <= n; a++) {
			for(int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(graph[i][j] == INF) {
				cout << 0 << " ";
			} else {
				cout << graph[i][j] << " ";
			}
		}
		cout << '\n';
	}
	
	
	
	return 0;
}
