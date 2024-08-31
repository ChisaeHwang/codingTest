#include <bits/stdc++.h>

using namespace std;

int n, ret = -10011;
int arr[100001];
int dp[100001]; // 현재 index에서 가장 큰 수 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		if (dp[i] < dp[i - 1] + arr[i]) { // dp[i - 1]이 음수일 경우 처리 
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			// 이전 수 안 합하기, 이전 수 합하기 
		}
		
		ret = max(ret, dp[i]);
	}
	
	cout << ret;
	
	
	return 0;
}
