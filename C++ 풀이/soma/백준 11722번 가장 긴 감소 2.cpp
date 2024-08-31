#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	
	int n;
	
	cin >> n;
	
	memset(dp, 1, sizeof(dp));
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[i] + dp[j]);
			}
		}
	}
	
	 
	return 0;
}
