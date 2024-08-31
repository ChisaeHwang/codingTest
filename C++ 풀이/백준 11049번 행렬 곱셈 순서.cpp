#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

#define MAX 1e9

using namespace std;

int dp[501][501];
int arr[501][2];

int go(int n, int m) {
	
	if(n == m) return 0;
	
	if(dp[n][m] != -1) return dp[n][m];
	
	int temp = MAX;
	
	for (int i = n; i < m; i++) {
		temp = min(temp, go(n, i) + go(i + 1, m) + arr[n][0] * arr[i][1] * arr[m][1]);
	}
	
	dp[n][m] = temp;
	
	return dp[n][m];
}

int main() {
	
	int num;
	cin >> num;
	
	memset(arr, 0, sizeof(arr));
	memset(dp, -1, sizeof(dp));
 
	for (int i = 0; i < num; ++i) {
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
 
	go(0, num - 1);
 
	cout << dp[0][num - 1] << '\n';
	
	return 0;
}
