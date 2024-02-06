#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int dp[10001];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	
	for(int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 1]));
	}  // i - 3번째와 i - 1번쨰를 무조건 마신 경우, i - 2번쩨인데 i - 3번쨰를 안 마셨을 경우
	 // 그리고 i - 1 번째를 마시고 이번엔 안 마신 경우 
	
	cout << dp[n] << '\n';
	
	return 0;
}
