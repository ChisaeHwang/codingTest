#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int dp[5001];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i <= n; i++) {
		dp[i] = INF;
	}

	dp[3] = 1;
	dp[5] = 1;
	
	for(int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	}

	if(dp[n] >= INF) { // INF 값에다가 +1이 더해질 수 있음 
		cout << -1 << '\n';
	} else {
		cout << dp[n] << '\n';	
	}
		
	return 0;
}
