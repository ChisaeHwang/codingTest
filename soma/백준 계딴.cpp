#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int dp[10001];
int n;

int main() {
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	
	for(int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	
	cout << dp[n] << '\n';
	
	return 0;
}
