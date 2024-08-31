#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2001][2001];
int arr[2001];
int n;

int solve(int i, int j) {
    if (i == j) {
    	return arr[i] * n;
	}
         
    
    if (dp[i][j] != -1) {
    	return dp[i][j]; 
	}
    
    int order = n - (j - i); 
    
    return dp[i][j] = max(solve(i + 1, j) + arr[i] * order, solve(i, j - 1) + arr[j] * order);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // dp 배열 초기화
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, n - 1) << '\n'; 
    
    return 0;
}

