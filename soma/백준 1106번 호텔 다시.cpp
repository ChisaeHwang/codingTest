#include <bits/stdc++.h>

using namespace std;

int dp[100001];
vector<pair<int, int>> arr;

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		int cost, num;
		cin >> cost >> num;
		arr.push_back({cost, num});
	}

	
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 1; j <= 100001; j++) {
			if(j - arr[i].first >= 0) {
				dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
			}
		} 
	}
	
	for(int i = 1; i <= 100001; i++) {
		if(dp[i] >= n) {
			cout << i << '\n';
			break;
		}
	}
	
	return 0;
}
