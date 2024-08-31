#include <iostream>
#include <vector>
#include <algorithm>
#define MOD ((int)1e9+7) 

using namespace std;

int dp[51];

int main(){

	int n;
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i=2; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2] + 1) % MOD;
	}
	
	cout << (dp[n] % MOD) << '\n';
	
	return 0;
}
