#include <bits/stdc++.h>

using namespace std;

int dp[1500001];
int t[1500001];
int p[1500001];
int n;


int main() {
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	
	int ret = 0;
	
	for(int i = 1; i <= n + 1; i++) {
		ret = max(ret, dp[i]);
		if(i + t[i] <= n + 1) {
			dp[i + t[i]] = max(dp[i + t[i]], ret + p[i]);
		}
	} 
	
	cout << ret << '\n'; 
	
	return 0;
}



