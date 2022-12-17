#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, x, y, nx, ny, temp, d;
int ret = 1;
int arr[101][101];
int visited[101][101];

void dfs(int y, int x)  {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (!visited[ny][nx] && arr[ny][nx] > d) { // 방문 안하고 수심이 될 때 
			dfs(ny, nx);
		} 
 	}
 	
 	return;
}


int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (d = 1; d < 101; d++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > d && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		} 	
		
		ret = max(ret, cnt);
	}
	
	cout << ret << '\n';
	
}
