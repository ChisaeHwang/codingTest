#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000 

int n;

int dp[1001][10];

int main() {
	
	cin >> n;
	
	for (int i = 0; i <= 9; i++) {
		dp[0][i] = 1;
	} 
	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD; 
		}
	}
	
	cout << dp[n][9] << '\n';
	
	return 0;
} 
