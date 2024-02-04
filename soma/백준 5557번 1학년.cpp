#include <bits/stdc++.h>

using namespace std;

long long int arr[101];
long long int dp[101][21];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dp[0][arr[0]] = 1;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 21; j++) {
			if(j - arr[i] >= 0) {
				dp[i][j] += dp[i - 1][j - arr[i]];
			}
			
			if(j + arr[i] < 21){
				dp[i][j] += dp[i - 1][j + arr[i]];
			}
		}
	}
	
	cout << dp[n - 2][arr[n - 1]] << '\n';
	// n - 1 번째는 마지막으로 나와야하는 숫자
	// 그러므로 n - 2번에서 arr[n - 1]이 나오는 경우의 수를 출력 
	
	
	return 0;
} 
