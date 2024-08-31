#include <bits/stdc++.h>

using namespace std;

#define MAX 1500001

int n;
int t[MAX];
int p[MAX];
int dp[MAX]; 

int main() {
	
	cin >> n; 
	
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	
	dp[1] = 0;
	int ret = 0;
	
	for (int i = 1; i <= n + 1; i++) {
		ret = max(ret, dp[i]);
		if (i + t[i] > n + 1) continue;
		else dp[i + t[i]] = max(dp[i + t[i]], ret + p[i]);
	}
	
	cout << ret << '\n';
	
	return 0;
}
