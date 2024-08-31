#include <bits/stdc++.h>

using namespace std;

int dp[5001];
int n, INF = 987654321;

int main() {

	cin >> n;
	
	fill(dp, dp + 5001, INF);
	
	dp[3] = 1;
	dp[5] = 1;
	
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	}
	
	if (dp[n] >= INF) cout << -1 << '\n';
	else cout << dp[n] << '\n';
	
	return 0;
} 
