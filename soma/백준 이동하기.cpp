#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
	 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	dp[0][0] = arr[0][0];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + arr[i][j + 1]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}
	
	cout << dp[n - 1][m - 1] << '\n';
	
	
	return 0; 
}
