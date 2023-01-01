#include <bits/stdc++.h>

using namespace std;

int n, m, temp, INF = 987654321;
int dp[10001];

int main() {
	
	cin >> n >> m;
	fill(dp, dp + 10001, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = temp; j <= m; j++) {
			dp[j] = min(dp[j], dp[j - temp] + 1); // 순회마다 매번 더 작은 값들은 비교해야함 
			
		}		//   0 1 2 					횟수가 추가되니 1 카운트 하는거임 
	}			// 1 0 1 2   ->  min(dp[i], dp[i-2] + 1) -> min[2, 1] 이런식으로 최적가능한 숫자를 계속 업로드 
 				// 2 0 0 1
 				
				
	// 최솟값은 항상 최댓값을 만들고 만들어야 함 
	if(dp[m] == INF) cout << -1 << '\n';
	else cout << dp[m] << '\n';
	
	
	return 0;
}
