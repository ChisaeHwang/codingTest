#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[501][501];

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		fill(graph[i], graph[i] + 501, INF);
		graph[i][i] = 0; // 본인은 가중치 X 
	}
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	for(int k = 1; k <= n; k++) {
		for(int a = 1; a <= n; a++) {
			for(int b = 1; b <= n; b++) {
				if(graph[a][k] == 1 && graph[k][b] == 1) { // a가 b보다 작다 
					graph[a][b] = 1;
				}
			}
		}
	}
	
	int cnt = 0;
	
	for(int a = 1; a <= n; a++) {
		int temp = 0;
		for(int b = 1; b <= n; b++) {
			if(graph[a][b] == 1 || graph[b][a] == 1){
				temp += 1;
				if(temp == n - 1) cnt++;
			} 
		}
	}
	
	cout << cnt;
	
	return 0;
}
