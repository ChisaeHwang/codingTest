#include <bits/stdc++.h>

#define MOD 10007

using namespace std;

int n;
int dp[1001][10]; // i로 시작해서 j로 끝나야함 


int main() {
	
	cin >> n;
	
	for (int i = 0; i <= 9; i++) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD; 
		}
	}
	
	cout << dp[n][9] << '\n';
	
	return 0;
}
