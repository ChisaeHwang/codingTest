#include <bits/stdc++.h>

using namespace std;

int v, e;
int graph[401][401];
const int INF = 987654321; 

int main() {
	
	cin >> v >> e;
	
	for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            graph[i][j] = INF;
        }
    }
	
	// 자기 자신에 대한 거리는 0으로 초기화합니다.
    for (int i = 0; i < v; ++i) {
        graph[i][i] = 0;
    }
	
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = c;
	}
	
	// 플로이드 와샬 
	int cycle = INF;
	
	for (int k = 0; k < v; k++) { // k번 정점을 거쳐 가는 경로 
		for (int i = 0; i < v; i++) { // 시작 정점 
			for (int j = 0; j < v; j++) { // 도착 정점 
				if(graph[i][k] != INF && graph[k][j] != INF // 이미 경로가 있는지 
				&& graph[i][k] + graph[k][j] < graph[i][j]){ // 최단 경로임 더 작아야 함 
					graph[i][j] = graph[i][k] + graph[k][j];
				} 
			}
		}	
	}
	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (graph[i][j] != INF && graph[j][i] != INF && i != j) {
				cycle = min(cycle, graph[i][j] + graph[j][i]);
			}
		}
	}
	
	if (cycle == INF) {
		cout << -1 << '\n';
	} else {
		cout << cycle << '\n';
	}

	
	return 0;
}
