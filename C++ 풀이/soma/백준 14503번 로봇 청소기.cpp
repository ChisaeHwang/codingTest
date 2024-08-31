#include <bits/stdc++.h>

using namespace std;

// ��, ��, ��, ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, x, y, d;
int ret;
vector<vector<int>> arr;
vector<vector<int>> visited;

void dfs() {
	
	// 4 ���� üũ 
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
	
	if(d > 1) { // Direction�� ��, ���� ��� 
		backD = d - 2; // �ݴ� ���� 
	} else {
		backD = d + 2;
	}
	int bX = x + dx[backD];
	int bY = y + dy[backD];
	if(bX >= 0 && bX < n && bY >= 0 && bY < m) {
		if(arr[bX][bY] == 0) { // �ڷ� ���� ������ ���� �ƴ� ��� 
			x = bX;
			y = bY;
			dfs();
		} else { // �ڷ� ���� ������ ���̸� ����
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
