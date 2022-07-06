#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];
int coin[25];

int main() {
	
	int t;
	cin >> t; 
	while(t--){
		int n, m;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> coin[i];
		}
		cin >> m;
		
		for(int i= 1 ; i < m+1; i++){
			dp[i] = 0;
		}
		dp[0] = 1;
		
		for(int i = 0; i < n; i++){
			for(int j = coin[i]; j <= m; j++){
				dp[j] += dp[j - coin[i]];
			}
		}
		
		cout << dp[m] << '\n';
	}
	
	
	
	return 0;
}
