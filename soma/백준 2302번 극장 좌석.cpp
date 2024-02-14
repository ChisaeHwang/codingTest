#include <bits/stdc++.h>
#define MOD 9901

using namespace std;

int dp[100001][3]; // 왼쪽 오른쪽 없거나 

int main() {
	
	int n;
	
	cin >> n;
	
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	
	
	for(int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][0]) % MOD;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % MOD; 
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	int ret = dp[n][0] + dp[n][1] + dp[n][2];
	
	cout << ret % MOD << '\n';	
	
	return 0;
}
