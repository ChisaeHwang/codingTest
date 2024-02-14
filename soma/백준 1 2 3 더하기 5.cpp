#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

long long dp[100001][3]; // 정수 n을 만들기 위해서 마지막 숫자가 m인 경우의 수 

int main() {
	
	int t;
	cin >> t;
		
	dp[1][1] = 1;
	dp[2][1] = 0;
	dp[3][1] = 1;
		
	dp[1][2] = 0;
	dp[2][2] = 1;
	dp[3][2] = 1;
		
	dp[1][3] = 0;
	dp[2][3] = 0;
	dp[3][3] = 1;
		
	for(int i = 4; i <= 100001; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD; // 1이 마지막에 더해지므로 i - 1  
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD; // 2이 마지막에 더해지므로 i - 2 
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD; // 3이 마지막에 더해지므로 i - 3 
	}
	
	while(t--) {
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << '\n';
	}
		
	return 0; 
}
