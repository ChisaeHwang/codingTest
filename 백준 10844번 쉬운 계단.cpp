#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000 

int n;
int dp[101][11]; 

int main() {
	
	cin >> n;
	
	for(int i = 1; i <= 9; i++){ // 1, 2, 3, 4, 5, 6 ...
    	dp[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if(j - 1 >= 0){
    			dp[i][j] += dp[i-1][j-1]; // 10, 21, 32, 43 ....
			}
			if(j + 1 <= 9){
				dp[i][j] += dp[i-1][j+1]; // 12, 23, 34, 45 ....
			}
			dp[i][j] %= MOD; // 오버플로우 방지 위해 % 연산 
		}
	}
	
	long long ans = 0;
	
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}
	
	cout << ans % MOD << '\n';
	
	return 0;
} 
