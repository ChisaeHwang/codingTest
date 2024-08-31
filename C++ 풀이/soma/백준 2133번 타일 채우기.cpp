#include <bits/stdc++.h>

using namespace std;

int n, ret;
int dp[31] = {1, 0, 3}; 

int main() {
	
	cin >> n;
	
	for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 2] * 3;
			
			for (int j = 4; j <= i; j += 2)
	        {
	            dp[i] += dp[i - j] * 2; // n=4부터는 새로운 도형이 추가된다. 하지만 n이 4,6,8,10...일때 도형의 모양이 모두 다르기 때문에 각각 dp[i]에 더해준다.
	        }
	}
	
	cout << dp[n] << '\n';

	
	
	return 0;
}
