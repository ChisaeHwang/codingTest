#include <bits/stdc++.h>

using namespace std;

int n, m, temp, INF = 987654321;
int dp[10001];

int main() {
	
	cin >> n >> m;
	
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (temp >= 10001) continue; 
		for (int j = temp; j <= m; j++) {
			dp[j] += dp[j - temp]; // �ش� ������ ������ ��� ����� ���� ��� �߰����ش� 
		}	
	}		 
 				
				 	
	// �ּڰ��� �׻� �ִ��� ����� ������ �� 
 	cout << dp[m] << '\n';
	
	
	return 0;
}
