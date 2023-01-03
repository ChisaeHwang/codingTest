#include <bits/stdc++.h>

using namespace std;

int n, k, temp;
int dp[101][10001]; // i번째 동전이 j번째까지 가는데 필요한 최소개수 
int cost[101];
int INF = 987654321;

int go(int cnt, int sum) {
	if (cnt == n) { // 시작하자마자 끝 base case 
		if (sum == 0) {
			return 0;
		} else {
			return INF;
		}
	}
	
	int ret = go(cnt + 1, sum); // 아무것도 안하고 count
	if (sum >= cost[cnt]) { // 더 크면 안되기에 
		ret = min(ret, go(cnt, sum - cost[cnt]) + 1);
	} 
	dp[cnt][sum] = ret;
	
	return ret;
}

int main() {	

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	
	int ret = go(0, k); // 0 -> k 까지
	
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n'; 

	
	return 0;
}
