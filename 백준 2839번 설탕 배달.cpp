#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[5001];

int main() {
	
	int n;
	cin >> n;
	
	for(int i=0; i<=n; i++){
		dp[i] = 10001;
	}
	
	dp[3] = 1;
	dp[5] = 1;
	
	for(int i=6; i<=n; i++){
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;	
	}
	
	if(dp[n] >= 10001){
		cout << -1 << '\n';
	} else {
		cout << dp[n] << '\n';	
	}
	
	return 0;
}
