#include <bits/stdc++.h>

using namespace std;

const int MAX = 987654321;
int dp[21][2];
vector<pair<int, int>> arr;

int main() {
	
	int n, k;
	
	cin >> n;
	
	arr.push_back({0, 0});
	for(int i = 1; i < n; i++) {
		int small, big;
		cin >> small >> big;
		arr.push_back({small, big});
	}
	
	cin >> k;
	
	for(int i = 0; i<= n; i++) {
        dp[i][0] = MAX;
        dp[i][1] = MAX;
    }
	
	dp[1][0] = 0; 
    dp[2][0] = arr[1].first; 
    dp[3][0] = min(arr[1].first + arr[2].first, arr[1].second);
	
	for(int i = 4; i <= n; i++) {
   		dp[i][0] = min(dp[i - 1][0] + arr[i - 1].first, dp[i - 2][0] + arr[i - 2].second); // 큰 점프 고려
        dp[i][1] = min(dp[i - 1][1] + arr[i - 1].first, min(dp[i - 2][1] + arr[i - 2].second,
		dp[i - 3][0] + k));
	}
	
	cout << min(dp[n][0], dp[n][1]) << '\n';
	
	
	return 0;
}
