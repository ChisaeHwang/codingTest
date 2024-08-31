#include <bits/stdc++.h>
using namespace std;

int dp[51][1001]; 
int arr[51];

int main() {

	int n, s, m;
	
	cin >> n >> s >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	dp[0][s] = 1;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(dp[i - 1][j]) {				
				if(j + arr[i] <= m) {
					dp[i][j + arr[i]] = 1;
				}
				if(j - arr[i] >= 0) {
					dp[i][j - arr[i]] = 1;
				}	
			}
		}
	}
	
	int ret = -1;
	
	for(int j = 0; j <= m; j++){
		if(dp[n][j]) {
			ret = j;
		}
	}
	
	cout << ret << '\n';

    return 0;
}

