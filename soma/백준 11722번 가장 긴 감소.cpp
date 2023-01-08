#include <bits/stdc++.h>

using namespace std;

int n, ret;
int arr[1001];
int dp[1001]; 


int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		
		cout << dp[i]; 
		ret = max(ret, dp[i]);
	}


	cout << ret;	
	
	return 0;
}
