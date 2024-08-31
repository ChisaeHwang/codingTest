#include <bits/stdc++.h>

using namespace std;

int t, n, ret;

int dp[1001];

int main() {
	
	cin >> t;
	
	while(t--) {

		cin >> n;
		
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		
		cout << dp[n] << '\n';
		
	}
	
	
	
	return 0;
} 
