#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int jh, sh;
int graph[101][101];
vector<int> place;

int main() {
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		fill(graph[i], graph[i] + n + 1, INF);
		graph[i][i] = 0; // 본인은 가중치 X 
	}
	
	
	for(int i = 1; i <= m; i++) {
	  int from, to, cost;
	  cin >> from >> to >> cost;
        graph[from][to] = min(graph[from][to], cost);
        graph[to][from] = min(graph[to][from], cost);
	}
	
	cin >> jh >> sh;
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		} 
	}
	
	int cnt = INF;
	int near = INF;
	int ret = -1;
	
	for(int i = 1; i <= n; i++) {
		if(i == jh || i == sh) continue;
		if(cnt > graph[jh][i] + graph[sh][i]) {
	        cnt = graph[jh][i] + graph[sh][i];
	    } 
	}

	
	for(int i = 1; i <= n; i++) {
		if(i == jh || i == sh) continue;
		int time = graph[jh][i] + graph[sh][i];
		if(cnt == time && graph[jh][i] <= graph[sh][i] && near > graph[jh][i]) {
			near = graph[jh][i];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(i == jh || i == sh) continue;
		int time = graph[jh][i] + graph[sh][i];
		if(cnt == time && near == graph[jh][i]) {
			place.push_back(i);
		}
	}
	
	if (place.size()) {
		sort(place.begin(), place.end());
		ret = place[0];
	}
	
	cout << ret << '\n';
	

	
	return 0;
}
