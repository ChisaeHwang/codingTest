#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001]; // °ÔÀÓ È½¼ö 

int main(){
	
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=n; i++){
		dp[i] = min(dp[i-1] + 1, dp[i-3] + 1);
	}
	
	cout << dp[n] << '\n'; 
	
	if(dp[n] % 2 == 0){
		cout << "CY" << '\n';
	} else {
		cout << "SK" << '\n';
	}
	
	return 0;
}
