#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[101][100001]; // 배낭에 넣을 물건 번호, 현재 배낭의 무게 
int w[101];
int v[101];


int main() {
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	} 
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	cout << dp[n][k] << '\n';
	
	
	
	return 0;
}
