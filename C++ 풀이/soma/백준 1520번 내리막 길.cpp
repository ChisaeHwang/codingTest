#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[501][501];
int arr[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(int x, int y) {

	if(n - 1 == x && m - 1 == y) {
		return 1;
	}	
	
	if(dp[x][y] == -1) { // 메모라이즈 안됐을 경우 
		dp[x][y] = 0;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(arr[x][y] > arr[nx][ny] && arr[nx][ny] != 0) {
				dp[x][y] += solve(nx, ny); // 경로 만큼 + 됨	
			}
		}
	}
	
	return dp[x][y];
}

int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ret = solve(0, 0);
	
	cout << ret << '\n';
	
	
	return 0;
}
