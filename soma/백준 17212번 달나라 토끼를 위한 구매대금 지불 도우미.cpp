#include <bits/stdc++.h>

using namespace std;

int dp[100001];
const int INF = 987654321;

int main() {
	
	int n;
	cin >> n;
	
	int coins[4] = {1, 2, 5, 7};         
	
	fill(dp, dp + n + 1, INF);
	
	dp[0] = 0;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 4; j++) {
			if(i - coins[j] >= 0) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	} 
	
	cout << dp[n] << '\n';
	
	
	return 0; 
}
