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
	            dp[i] += dp[i - j] * 2; // n=4���ʹ� ���ο� ������ �߰��ȴ�. ������ n�� 4,6,8,10...�϶� ������ ����� ��� �ٸ��� ������ ���� dp[i]�� �����ش�.
	        }
	}
	
	cout << dp[n] << '\n';

	
	
	return 0;
}
