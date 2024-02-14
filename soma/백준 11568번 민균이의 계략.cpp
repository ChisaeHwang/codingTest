#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	fill(dp, dp + n + 1, 1);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			} 
		}
	}


	int ret = 0;
	
	for(int i = 0; i < n; i++) {
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	return 0; 
}
