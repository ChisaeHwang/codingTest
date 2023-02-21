#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000 

int n;

int dp[101][11];

int main() {
	
	cin >> n;
	 
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				dp[i][j] += dp[i-1][j-1];
			}
			if (j + 1 <= 9) {
				dp[i][j] += dp[i-1][j+1];
			}
			dp[i][j] %= MOD;
		}
	}
	
	long long ret = 0;
	
	for (int i = 0; i <= 9; i++) {
		ret += dp[n][i];
	}
	
	cout << ret % MOD << '\n';
	
	return 0;
} 
