#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main(){
	
	int n;
	cin >> n;
	
	dp[1] = dp[3] = 1e9; 
    dp[2] = dp[5] = 1;
    dp[4] = 2;
	
	for(int i=6; i<=n; i++){
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	}
	
	if(dp[n] == 1e9){
		cout << "-1" << '\n';
	} else {
		cout << dp[n] << '\n';	
	}
	
	return 0;
}
