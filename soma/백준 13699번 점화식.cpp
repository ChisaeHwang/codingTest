#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[36];

int main() {
    cin >> n;
    
    dp[0] = 1;

    
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= i; j++) {
    		dp[i] += dp[j - 1] * dp[i - j];
		}            // t(1) * (t-2) �̱⿡ 
	}
	
	cout << dp[n] << '\n';

    return 0;
}

