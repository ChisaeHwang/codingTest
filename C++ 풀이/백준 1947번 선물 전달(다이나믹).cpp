#include <iostream>
using namespace std;

long long dp[1000001];

int main() {
	
	int n;
	cin >> n;
	
	dp[1] = 0; // 사람 한명, 선물 못 받음 
	dp[2] = 1; // 서로 가능 경우의수 1 
	
	for(int i=3; i<=n; i++){
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;
	}
	
	cout << dp[n] <<'\n';
	
	return 0;
}

