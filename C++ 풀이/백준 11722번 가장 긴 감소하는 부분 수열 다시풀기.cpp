#include <bits/stdc++.h>

using namespace std;


int n, sum, INF = 987654321;
int dp[1001];
int arr[1001];

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dp[0] = 1; 
	
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (temp > arr[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	cout << sum << '\n';
	
	
	return 0;
}
