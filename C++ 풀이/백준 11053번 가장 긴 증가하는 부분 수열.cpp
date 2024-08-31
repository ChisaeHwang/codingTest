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
		dp[i] = 1;
		int temp = arr[i];
		for (int j = 1; j <= i; j++) {
			int value = arr[j];
			if (temp > value) {
				dp[i] = max(dp[i], dp[j] + 1); // count
			}
		}
		
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	
	return 0;
}
