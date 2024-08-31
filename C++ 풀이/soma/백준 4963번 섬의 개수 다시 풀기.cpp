#include <bits/stdc++.h>

using namespace std;

int n, m; 
int dx[] = {0, 0, 1, -1 ,1 ,1 ,-1 ,-1};
int dy[] = {1, -1 ,0 ,0 ,1 ,-1 ,1 ,-1};
int arr[101][101];
int visited[101][101];
vector<int> ret;

void bfs(int y, int x, int cnt) {
	
	queue<pair<int, int>> q;
	visited[y][x] = cnt;
	q.push({y, x});
	
	while(q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] == 0) continue;
			q.push({ny, nx});
			visited[ny][nx] = cnt; // 방문체크 
		}
	}
	
}



int main() {
	
	while(true) {
		
		cin >> m >> n;
		
		if (n == 0 && m == 0) break;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				visited[i][j] = 0;
			}
		}
		
		int cnt = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(arr[i][j] == 0 || visited[i][j]) continue;
				bfs(i, j, ++cnt);
			}
		}
		
		cout << cnt << '\n';
		
	}
	
	
	return 0;
}
