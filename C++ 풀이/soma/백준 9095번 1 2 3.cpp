#include <bits/stdc++.h>

using namespace std;


int n;
int dp[11];

int main() {
	
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}	
	
	for(int i = 0; i < n; i++) {
		int ret;
		cin >> ret;
		cout << dp[ret] << '\n';
	}
	
	return 0;
}



