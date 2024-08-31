#include <iostream>
#include <algorithm>

using namespace std;

int n,k,tmp,ret = -1000000;
int dp[100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		dp[i] = dp[i - 1] + tmp;
		
		// i - 1 번째 수와 i 번째 수의 합 구하기 
	}
	
	for (int i = k; i <= n; i++) {
		ret = max(ret, dp[i] - dp[i - k]);
	}
	
	cout << ret;
	
}
