#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101];
string s;

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	
	while(q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m | visited[ny][nx]) continue;
			if (arr[ny][nx] == 0) continue;
			q.push({ny, nx});
			visited[ny][nx] = visited[y][x] + 1;   
		}
	}
	
	cout << visited[n - 1][m - 1] << '\n';
		 
	
	
	return 0;
}
