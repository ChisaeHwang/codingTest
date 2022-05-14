#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001];
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		dp[0][0] = dp[1][0] = 0;
		
		for(int i=1; i<=n; i++){
			cin >> dp[0][i];
		}
		
		for(int i=1; i<=n; i++){
			cin >> dp[1][i];
		}
		
		// 대각선으로 -1 -2 값을 비교 후 더 높은 값을 선택 
		for(int i=2; i<=n; i++){
		dp[0][i] =	max(dp[1][i-1], dp[1][i-2]) + dp[0][i];
		dp[1][i] = 	max(dp[0][i-1], dp[0][i-2]) + dp[1][i];
		}
		
		int ans = max(dp[1][n], dp[0][n]);
		cout << ans << '\n';
		
	}
	
	
	
	return 0;
}
