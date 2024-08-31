#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t[1500001]; 
int p[1500001]; 
int n;
int dp[1500001] = { 0, };

void go(){
	dp[1] = 0;
	int ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		ans = max(ans, dp[i]);
		if (i + t[i] > n + 1)
			continue;
		else {
			dp[i + t[i]] = max(dp[i + t[i]], ans + p[i]);
		}
	}
	
	cout << ans << '\n';
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	
	go();

	return 0;
} 
