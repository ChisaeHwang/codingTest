#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[10001]; // dp[i] = t : i 시간 동안 최대 t 점수 

int main() {
	
	int n, t;
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		int k, s;
		cin >> k >> s;
		for(int j = t; j >= k; j--){
			dp[j] = max(dp[j], dp[j - k] + s);
		} 
	} 
	
	cout << dp[t] << '\n';
	
	return 0; 
}
