#include <iostream>
#include <vector>
#include <algorithm>
#define MOD ((int)1e9+7) 
using namespace std;

long long dp[1001][1001];

int main(){
	
	int n, m;
	cin >> n >> m;
	
	dp[0][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			// ℃ 规过, ￠ 规过, ①规过 
			dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]) % MOD;
		}
	}
	
	cout << dp[n][m] << '\n';
	
	return 0;
}
