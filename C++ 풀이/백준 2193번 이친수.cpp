#include <iostream>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	long long dp[101];
	
	dp[1] = 1;
	dp[2] = 1;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	} // 마지막수가 0이면 n-1의수 1이면 n-2의 수 
	
	cout << dp[n];
	
	
	return 0;
}


// 다른 풀이 방법 
//	dp[1][0] = 0;  dp[길이][끝나는 수]... 0으로 끝나는지 1으로 끝나는지 
//	dp[1][1] = 1;  길이가 1일 경우 1으로 끝나는거만 가능 
//
//	for (int i = 2; i <= N; i++) {
//		if (dp[i - 1][0] >= 1) { // 0으로 끝나면 0,1 두개다 가능 
//			dp[i][0] += dp[i - 1][0];
//			dp[i][1] += dp[i - 1][0];
//		}
//		if (dp[i - 1][1] >= 1) {
//			dp[i][0] += dp[i - 1][1]; // 1으로 끝나면 0만 가능 
//		}
//	}
//
//	printf("%lld", dp[N][0] + dp[N][1]);
