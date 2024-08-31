#include <bits/stdc++.h>

using namespace std;

int dp[10001]; // dp[i] i원에 얼마나 경우의 수가 있는지 

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
	dp[0] = 1;
	
	for(int i = 0; i < n; i++ ) {
		int coin;
		cin >> coin; // 각 coin을 추가할 때 마다 경우의 수 업데이트
		for(int j = coin; j <= m; j++) {
			dp[j] += dp[j - coin]; // j원이 되기전이 j - coin을 통해서 이전에 값을 + 해줌으로써 
		} // dp 갱신 가능 
	}

	cout << dp[m] << '\n';
	
	return 0;
} 
