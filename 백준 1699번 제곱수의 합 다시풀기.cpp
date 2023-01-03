#include <bits/stdc++.h>

int dp[100001];
int arr[100001]; 
int n, temp;

using namespace std;



int main() {

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		arr[i] = i * i;
	}
	
	for (int i = 1; i <= n; i++) {
		temp = arr[i];
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i - temp] + 1);	
		}
	}
	
	cout << dp[n] << '\n';



	return 0;
} 
