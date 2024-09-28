#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[501][501];
int visited[501][501] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int a, int b) {
	
	int cnt = 1;
	
	visited[a][b] = 1;
	queue<pair<int, int>> q;
	
	q.push({a, b});
	
	while(q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 1 && !visited[nx][ny]) {
				q.push({nx, ny});
				cnt++;
				visited[nx][ny] = 1;
			}
		}
	}
	
	
	return cnt;
}

int main() {
	
	cin >> n >> m;
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ret = 0;
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visited[i][j] && arr[i][j] == 1) {
				ret = max(ret, bfs(i, j));
				cnt++;
			}
		}
	}
	

		cout << cnt << '\n';
	cout << ret << '\n';
}
