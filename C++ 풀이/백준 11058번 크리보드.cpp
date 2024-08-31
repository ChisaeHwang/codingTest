#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

long long dp[101];

int main() {
	
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 5;
	
	for(int i = 6; i <= n; i++){
		dp[i] = max({dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4});
	}
	
//	for (int i = 6; i <= N; i++) {
//		dp[i] = dp[i - 1] + 1;
//		for (int j = 1; j <= i - 2; j++)
//			dp[i] = max(dp[i], dp[i - 2 - j] * (j + 1));
//	}
	
	cout << dp[n] << '\n';
	
	return 0;
}
