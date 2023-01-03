#include <bits/stdc++.h>

using namespace std;

#define MOD 15746

int n, ret;
int dp[1000001]; // ���� n�� ���� �� �ִ� 2�� ������ ������ 15746���� ���� ������ 

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
