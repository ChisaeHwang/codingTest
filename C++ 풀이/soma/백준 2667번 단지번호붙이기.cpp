#include <bits/stdc++.h>

using namespace std;

int visited[26][26];
int arr[26][26];
int sum[26*26];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, ret; 
string s;

void bfs(int y, int x, int cnt) {
	
	queue<pair<int, int>> q;
	q.push({y, x}); // x y를 queue에 넣어줌 
    visited[y][x] = cnt; // 방문 체크 
    
    while(q.size()) {
    	int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
			if (arr[ny][nx] == 1) {
				q.push({ny, nx});
				visited[ny][nx] = cnt;
			}	
		}
	}
    
    
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 || visited[i][j]) continue;
			bfs(i, j, ++cnt);
		}
	}
	
	cout << cnt << '\n';
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[visited[i][j]] += 1; // cnt에 따라 count 
		}
	}
	
	sort(sum + 1, sum + cnt + 1);
	
	for (int i = 1; i <= cnt; i++) {
		cout << sum[i] << '\n';
	}
	
	return 0;
} 
