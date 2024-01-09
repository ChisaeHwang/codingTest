#include <bits/stdc++.h>

using namespace std;

// 북, 동, 남, 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, x, y, d;
int ret;
vector<vector<int>> arr;
vector<vector<int>> visited;

void dfs() {
	
	// 4 방향 체크 
	for(int i = 0; i < 4; i++) {
		int nextD = (d + 3 - i) % 4;
		int nextX = x + dx[nextD];
		int nextY = y + dy[nextD];
		
		if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || arr[nextX][nextY] == 1) {
			continue;
		}
		
		if(arr[nextX][nextY] == 0 && visited[nextX][nextY] == 0) {
			visited[nextX][nextY] = 1;
			d = nextD;
			x = nextX;
			y = nextY;
			ret++;
			dfs();
		}
	}
	
	int backD;
	
	if(d > 1) { // Direction이 남, 서일 경우 
		backD = d - 2; // 반대 방향 
	} else {
		backD = d + 2;
	}
	int bX = x + dx[backD];
	int bY = y + dy[backD];
	if(bX >= 0 && bX < n && bY >= 0 && bY < m) {
		if(arr[bX][bY] == 0) { // 뒤로 가는 방향이 벽이 아닌 경우 
			x = bX;
			y = bY;
			dfs();
		} else { // 뒤로 가는 방향이 벽이면 종료
			return; 
		} 
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	arr.resize(n, vector<int>(m));
	visited.resize(n, vector<int>(m, 0));
	
	cin >> x >> y >> d;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	visited[x][y] = 1;
	ret++;
	
	dfs();
	
	cout << ret << '\n'; 

	return 0;
}
