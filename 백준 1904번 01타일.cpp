#include <iostream>
#include <algorithm>

#define MOD 15746

int dp[1000001];

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}
	
	cout << dp[n] << '\n';
	
	return 0;
} 
