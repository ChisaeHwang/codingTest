#include <bits/stdc++.h>

using namespace std;

int n, k, ret;
int dp[10001]; // 배낭에 넣을 물건 번호, 현재 배낭의 무게 
int arr[10001];

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	} 

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}
	
	cout << dp[n] << '\n';
	
	
	return 0;
}
