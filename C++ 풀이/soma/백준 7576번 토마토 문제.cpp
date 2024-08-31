#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;

void bfs() {
	
	while(q.size()) {
		int y = q.front().first ;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] == -1 || arr[ny][nx] == 1) continue;
			q.push({ny, nx});
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	
}

int main() {
	
	cin >> m >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			
			if (arr[i][j] == 1) {
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	
	bfs();
	
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	ret = max(ret, visited[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
        	if (visited[i][j] == 0 && arr[i][j] == 0) ret = 0;
        }
    } 
	
	cout << ret - 1 << '\n';
	
	return 0;
}
