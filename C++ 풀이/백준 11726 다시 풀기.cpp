#include <bits/stdc++.h>

using namespace std;

#define MOD 10007

int n, ret;
int dp[1001]; 

int main() {
	
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	
	cout << dp[n] << '\n';
	
	
	return 0;
}

// Top-down 방식으로 해결한 경우 
//#include <iostream>
//
//using namespace std;
//
//int D[1001];
//int tile(int k){
//    if (k == 1) return 1;
//    if (k == 2) return 2;
//    if (D[k] > 0) return D[k];		// 배열에 값 저장되었으면 바로 출력
//	D[k] = tile(k-1) + tile(k-2);
//	D[k] %= 10007;
//	return D[k];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << tile(n);
//	return 0;
//}
