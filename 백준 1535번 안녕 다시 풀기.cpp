#include <bits/stdc++.h>

using namespace std;

int n, k, w, v;
int dp[101]; // 무게당 최댓값 
int cost[101];
int happy[101]; 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	
	
	for (int i = 0; i < n; i++) {
		cin >> happy[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 100; j > cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
		}
	}
	
	cout << dp[100] << '\n';
	
	return 0;
}   
