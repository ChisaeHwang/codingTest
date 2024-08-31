#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

long long dp[1000001];

int main() {
	
	int n;
	
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	dp[5] = 8;
	
	for(int i = 6; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	
	cout << dp[n]<< '\n';
	
	
	return 0;
}
