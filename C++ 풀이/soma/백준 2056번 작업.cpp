#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int times[10001];

int main() {
	
	int n;
	
	cin >> n;
	
	vector<vector<int>> preTask(n + 1);
	
	for(int i = 1; i <= n; i++) {
		cin >> times[i];
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++) {
			int pre;
			cin >> pre;
			preTask[i].push_back(pre);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(auto pre : preTask[i]) {
			cnt = max(cnt, dp[pre]);
		}
		dp[i] = cnt + times[i];
	}
	
	int ret = 0;
	 
	for(int i = 1; i <= n; i++){
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	return 0;
}
