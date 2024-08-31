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
	
	// ù�ٿ��� ������ ��ġ(���ų� �����̰ų� �������̰ų�)�� �𸣱� ���� 
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	
	for(int i=2; i<=n; i++){
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]);
		// 0�� 0, 1, 2 �� ��ġ ���� 
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]);
		// 1�� 0, 2 �� ��ġ ���� 
		dp[i][2] = (dp[i-1][0] + dp[i-1][1]);
		// 2�� 0, 1 �� ��ġ ���� 
	}
	
	// ��� ����� �� ���ϱ� 
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
	
	return 0;
}
