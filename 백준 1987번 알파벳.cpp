#include <bits/stdc++.h>

using namespace std;

// 알파벳인걸 잘 이용해야함 

int n, m, ret, visited[30];
char arr[21][21];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int r = 0;

void bfs(int y, int x, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m ) continue;
		int next = (int)(arr[ny][nx] - 'A');
		
		if (visited[next] == 0){
			visited[next] = 1;
			bfs(ny, nx, cnt + 1);
			visited[next] = 0; // 올라오면서 걸어둔 check등을 다 풀어줌 
		}
	}
	return;
}


int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	visited[(int) arr[0][0] - 'A'] = 1;
	
	bfs(0, 0, 1);
	
	cout << ret << '\n';
	
	return 0;
}
