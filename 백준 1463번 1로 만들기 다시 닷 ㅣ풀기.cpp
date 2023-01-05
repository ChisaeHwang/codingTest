#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];

int go(int num) {
	
	if (num == 1) return 0; 
	if (dp[num] != -1) return dp[num];
	
	int ret = go(num - 1) + 1;
	if(num % 3 == 0) ret = min(ret, go(num / 3) + 1);
	if(num % 2 == 0) ret = min(ret, go(num / 2) + 1); 
	dp[num] = ret;
	
	return ret;
}

int main() {
	
	cin >> n;
	
	fill(dp, dp + 1000001, -1);
	
	cout << go(n) << '\n';
	
	
	return 0;
} 
