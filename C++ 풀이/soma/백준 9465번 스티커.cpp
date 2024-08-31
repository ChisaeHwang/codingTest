#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;
	
	cin >> t;
	
	while(t--) {
		
		int n;
		
		cin >> n;
		
		int arr[100001][2];
		int dp[100001][2];
		
		for(int i = 0; i < 2; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> arr[j][i];
			}
		}
		
		dp[1][0] = arr[1][0]; // 위의 행 
		dp[1][1] = arr[1][1]; // 아래 행 
		
		for(int i = 2; i <= n; i++) {
			dp[i][0] = max(dp[i - 2][1], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = max(dp[i - 2][0], dp[i - 1][0]) + arr[i][1]; 
		}
		
		cout << max(dp[n][0], dp[n][1]) << '\n';		
		
	}
	
	return 0;
}
