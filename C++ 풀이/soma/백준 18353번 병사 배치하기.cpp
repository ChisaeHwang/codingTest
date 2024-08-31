#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2001];
int dp[2001];
int ret = 0; 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for (int i = 1; i < n; i++) { // 뒤에 병사 
		for (int j = 0; j < i; j++) { // 앞에 병사 
			if(arr[i] < arr[j]) { // 앞 병사가 더 큰 경우 
				dp[i] = max(dp[i], dp[j] + 1); // count	
			}
			ret = max(ret, dp[i]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i]);
	} 
	
	cout << n - ret << '\n';
	
	return 0;
}
