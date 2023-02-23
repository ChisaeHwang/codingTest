#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101];
queue<pair<int, int>> q; 

void bfs(int x, int y) {
    
    q.push({x, y});
    visited[x][y] = 1;
    
    while(q.size()) {
    	int x = q.front().first;
    	int y = q.front().second;
    	q.pop();
    	
    	for (int i = 0; i < 4; i++) {
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		
    		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    		if (visited[nx][ny]) continue;
    		if (arr[nx][ny] == 0) continue;
    		visited[nx][ny] = visited[x][y] + 1;
    		q.push({nx, ny});
		}
	}
}

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		scanf("%1d", &arr[i][j]);
		}
	}
	
	bfs(0, 0);
	
	cout << visited[n - 1][m - 1] << '\n';
    
    return 0;
}
