#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

int dp[1001][10001]; // i번째까지 물건을 살펴보고, 용량이 j 였을 때 
int w[10001];
int t[10001];

int main() {
	
	int n, m;
	
	cin >> m >> n; 
	
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> t[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
		 	if(t[i] <= j){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + w[i]);
			} else {
				dp[i][j] = dp[i - 1][j];
			} 
		}
	} 
	
	cout << dp[n][m] << '\n';
	
	return 0; 
}
