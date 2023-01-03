#include <bits/stdc++.h>

using namespace std;

// top down 방식으로 풀기 위에서 아래로 
int n, dp[1000001]; // 각 idx당 나올 수 있는 최소 경우의 수 

int go(int n) {
	
	if (n == 1) return 0; //기본 케이스 
	if (dp[n] != -1) return dp[n]; // 이미 계산한 값 


	int ret = go(n - 1) + 1;
	if (n % 3 == 0) ret = min(ret, go(n / 3) + 1);
	if (n % 2 == 0) ret = min(ret, go(n / 2) + 1);
	dp[n] = ret;
	
	return ret; 
}

int main() {
	
	cin >> n;
	
	fill(dp, dp + 1000001, -1);
	
	cout << go(n) << '\n';
	
	return 0;	
}
