#include <bits/stdc++.h>

using namespace std;

int n, ret;
int arr[1001];
int dp[1001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++) {
			if (dp[i] > dp[j] && dp[i] < dp[j] + arr[i]) {
				dp[i] = max(dp[i], dp[j] + arr[i]) ; // count
			}
		}
		
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	return 0;	
}
