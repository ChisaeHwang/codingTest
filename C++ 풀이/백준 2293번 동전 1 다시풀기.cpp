#include <bits/stdc++.h>

using namespace std;

int n, m, temp, INF = 987654321;
int dp[10001];

int main() {
	
	cin >> n >> m;
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (temp >= 10001) continue; 
		for (int j = temp; j <= m; j++) {
			dp[j] += dp[j - temp]; // 해당 값에서 가능한 모든 경우의 수를 계쏙 추가해준다 
		}	
	}		 
 				
				 	
	// 최솟값은 항상 최댓값을 만들고 만들어야 함 
 	cout << dp[m] << '\n';
	
	
	return 0;
}
