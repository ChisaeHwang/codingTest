#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int p[10001];
int n;

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
			// i - j를 통해 각 dp[i]마다 최대값들을 가져옴
			// -> 그것들을 그대로 메모리라이징 해주어 최고값들을 갱신 
		}
	}
	
	cout << dp[n] << '\n';
	
	
	return 0;
}
