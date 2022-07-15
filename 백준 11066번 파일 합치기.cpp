#include <iostream>
#include <algorithm>
#include <string> 

#define MOD 1000000000

using namespace std;

int dp[501][501];
int cost[501];
int file[501]; 

int main() {
	
	int t, n;
	cin >> t;
	
	while(t--){
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> file[i];
			// 1 ~ n 번째 까지의 합 
			cost[i] = cost[i - 1] + file[i];
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n - i; j++){
				dp[j][i + j] = MOD;
				for(int k = j; k < j + i; k++){
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + cost[i + j] - cost[j - 1]);
				}
			}
		}
		
		cout << dp[1][n] << '\n';
	}
	
	
	
	return 0;
} 
