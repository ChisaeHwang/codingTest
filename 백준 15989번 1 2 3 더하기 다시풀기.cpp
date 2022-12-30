#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll t, n, dp[10001];


int main() {
	
	cin >> t; 
	
	dp[0] = 1; // 0을 만드는 방법은 1이다
	
	for (int i = 1; i <= 3; i++) { // 1, 2, 3
		for (int j = 1; j <= 10000; j++) {
			if (j - i >= 0) {
				dp[j] += dp[j - i]; // 음수가 들어가면 이 값이 이상해짐 
			}
		}
	} 
	
	while(t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
} 
