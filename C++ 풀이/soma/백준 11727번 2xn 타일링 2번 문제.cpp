#include <bits/stdc++.h>
#define MOD 1000000000 

using namespace std;

int dp[101][10];

int main() {
	
	int n;
	
	cin >> n;

	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1; 
	}
	
	for(int i = 1; i <= 9; i++){
		dp[2][i] = 2; 
	}
	
	dp[2][0] = 1;
	dp[2][9] = 1; 
	
	
	for(int i = 3; i <= n; i++) {
		for(int j = 0; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			cout << dp[i][j] << '\n';	
		} // 계단 수 이므로 아래 숫자랑 위에 숫자를 그만큼 더해주면 끗 ! 
	} 
	
	int ret = 0;
	
	for(int i = 0; i <= 9; i++) {
		ret += dp[n][i];
	}
	
	cout << ret << '\n';
	
	return 0;
}
