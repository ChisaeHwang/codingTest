#include <bits/stdc++.h>
#include <algorithm>;

using namespace std;

// i, j, 오늘 방향으로 왔는지 
int dp[1002][1002][3]; // 하단 우측, 하단, 하단 좌측  
int arr[1002][1002];
int n, m; 
const int MAX = 987654321;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			for(int k = 0; k < 3; k++) {
				dp[i][j][k] = MAX;
				if(i == 1) {
					dp[i][j][k] = arr[i][j];
				}	
			}
		}
	}
	
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
  			if (j > 1){ // 하단 우측 방향으로 옴 
  				dp[i][j][0] = min(dp[i][j][0], arr[i][j] + min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]));
			}
			
			// 하단으로 바로 옴 
            dp[i][j][1] = min(dp[i][j][1], arr[i][j] + min({dp[i - 1][j][0], dp[i - 1][j][2]})); 
            
			if (j < m) { // 하단 좌측 방향으로 옴 
    			dp[i][j][2] = min(dp[i][j][2], arr[i][j] + min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]));         	
			}
	
		}
	}
	
	int ret = MAX;
	
	for(int j = 1; j <= m; j++) {
		for(int k = 0; k < 3; k++){
			ret = min(ret, dp[n][j][k]);
		}
	}
	
	cout << ret << '\n';

	return 0;
}
