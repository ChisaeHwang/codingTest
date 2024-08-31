#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

vector<int> v[100001];
int dp[100001];

void dfs(int num){
	for(int i = 0; i < v[num].size(); i++){
		dp[v[num]] += dp[num];
		dfs(v[num]);
	}
}

int main() {
	
	int n, m, k, w;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (i == 1)continue;
		v[tmp].push_back(i);
	}
	for (int j =0; j < m; j++) {
		cin >> k >> w;
		dp[k] += w;
	}
	dfs(1);
 
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	
	return 0; 
}
