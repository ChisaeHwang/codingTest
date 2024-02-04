#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
	    dp[i] = 1;
	}
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
			if(arr[i] > arr[j] && dp[i] + 1 > dp[j]) {
				dp[j] = dp[i] + 1;
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
