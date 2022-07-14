#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int main() {
	
	int n, k; // 넣을 물건, 무게 제한 
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> v[i]; // 무게, 가치 
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(j >= w[i]){  
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);  
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	cout << dp[n][k] << '\n';
	
	return 0;
}
