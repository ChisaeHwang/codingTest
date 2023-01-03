#include <bits/stdc++.h>

using namespace std;

#define MOD 15746

int n, ret;
int dp[1000001]; // 길이 n당 만들 수 있는 2진 수열의 개수를 15746으로 나눈 나머지 

int go(int num) {
	if (num == 1) return 1;
	if (num == 2) return 2;
	
	if (num == n) return num;
	
	dp[num] = (go(num - 1) + go(num - 2)) % MOD;
	
	return dp[num];
} 

int main() {
	
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	
	cout << go(n) << '\n';
	
	return 0;
}
