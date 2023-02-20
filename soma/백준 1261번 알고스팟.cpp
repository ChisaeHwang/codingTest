#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101];
int INF = 987654321;

int main() {
	
	cin >> m >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			visited[i][j] = INF;
		}
	}
	
	queue<pair<int, int>> q;
	q.push({0 ,0});
	visited[0][0] = 0;
	
	while(q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (arr[ny][nx] == 1) {
				if (visited[ny][nx] > visited[y][x] + 1) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ny, nx});	
				}
			} else {
				if (visited[ny][nx] > visited[y][x]) {
					visited[ny][nx] = visited[y][x];
					q.push({ny, nx});
				}
			}
		}
	}	
	
	cout << visited[n - 1][m - 1] << '\n';
	
	
	return 0;
} 
