#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[1000001]; 

int main() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		double ret = 0;
		for(int j = 1; j <= 6; j++){
			ret += (dp[i - j] + 1) / 6.0;
			dp[i] = ret;
		}
	}
	
	cout << dp[0] << '\n';
	
	return 0;
} 
