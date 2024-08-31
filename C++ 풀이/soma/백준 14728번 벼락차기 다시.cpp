#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[101][10001];
int w[101]; // ���� 
int v[101]; // �� 

int main() {
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
		cin >> v[i];
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(j >= w[i]) { // ���ΰ� ������ ��� 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);	
			} else { // ���ΰ� �Ұ��� �� ��� 
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	cout << dp[n][m] << '\n';
	
    return 0;
}

