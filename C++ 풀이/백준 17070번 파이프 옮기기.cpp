#include <bits/stdc++.h>

using namespace std;

int arr[21][21];
int dp[21][21][3]; // 가로, 세로, 대각선 경우
int n; 

bool check (int y, int x, int c) {
	if (c == 0 || c == 2) { // 가로 또는 세로의 경우 
		if (arr[y][x] == 0) return true; // 벽이 없으면 
	} else if (c == 1) {
		if (arr[y][x] == 0 && arr[y - 1][x] == 0 && arr[y][x - 1] == 0) return true;
	} 
	
	
	return false;
}

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}	
	
	dp[1][2][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0]; 

            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2]; 
            
            if(check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];
            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1]; 
		}
	}
	
	int ret = dp[n][n][0]; 
    ret += dp[n][n][1]; ret += dp[n][n][2];  
    cout << ret << "\n"; 
	
	
	
	return 0;
}
