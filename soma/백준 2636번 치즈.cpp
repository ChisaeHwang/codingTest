#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, t, cnt, ret;
queue<pair<int, int>> q;
queue<pair<int, int>> ch;

int bfs(int x, int y) {
	
	q.push({x, y});
	visited[x][y] = 1;
	cnt = 0;
	t++;
	
	while(q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 0;
				cnt++;
			} else {
				q.push({nx, ny});
			}
			visited[nx][ny] = 1;
		}
	}
	
	if (cnt == 0) {
		cout << --t << '\n' << ret;
		return 1;
	} else {
		ret = cnt;
		return 0;
	}
	
	
}


int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	while(true) {
		
		if (bfs(0, 0)) break;
		
		memset(visited, 0, sizeof(visited));
		
	}
	
	
	
	
	
	return 0;
}
