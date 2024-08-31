#include <bits/stdc++.h>

using namespace std;

int dp[10001]; // dp[i] i���� �󸶳� ����� ���� �ִ��� 

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
	dp[0] = 1;
	
	for(int i = 0; i < n; i++ ) {
		int coin;
		cin >> coin; // �� coin�� �߰��� �� ���� ����� �� ������Ʈ
		for(int j = coin; j <= m; j++) {
			dp[j] += dp[j - coin]; // j���� �Ǳ����� j - coin�� ���ؼ� ������ ���� + �������ν� 
		} // dp ���� ���� 
	}

	cout << dp[m] << '\n';
	
	return 0;
} 
