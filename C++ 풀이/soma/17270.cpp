#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[1001][1001];
vector<int> place;

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
	  fill(graph, graph + 1001, INF);
	}
	
	for(int i = 0; i < m; i++) {
	  int from, to, cost;
	  cin >> from >> to >> cost;
	  graph[from][to] = cost;
	  graph[to][from] = cost;
	}
	
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		} 
	}
	
	int j, s;
	
	cin >> j >> s;
	
	cout << graph[j][1] << '\n';
	
	
	
	return 0;
}
