#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[25];
int dp[10001];

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			dp[j] += dp[j - arr[i]]
		}
	}
	
	
	

	
	return 0;
}
