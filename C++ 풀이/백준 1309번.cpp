#include <iostream>
#include <algorithm>
#define MOD 9901

using namespace std;

int dp[100000][3];
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	// 첫줄에는 사자의 위치(없거나 왼쪽이거나 오른쪽이거나)를 모르기 때문 
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	
	for(int i=2; i<=n; i++){
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]);
		// 0은 0, 1, 2 다 배치 가능 
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]);
		// 1은 0, 2 만 배치 가능 
		dp[i][2] = (dp[i-1][0] + dp[i-1][1]);
		// 2은 0, 1 만 배치 가능 
	}
	
	// 모든 경우의 수 더하기 
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
	
	return 0;
}
