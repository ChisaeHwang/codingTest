#include <bits/stdc++.h>

using namespace std;

int n, m, c;

int dp[101][301][301]; // �ֹ�, ġ�����, ����Ƣ�� ������ ���� �ִ� 
int chee[301];
int pota[301];


int main() {
	
	cin >> n >> m >> c;
	
	for(int i = 1; i <= n; i++) {
		cin >> chee[i] >> pota[i];
	}
	
    memset(dp, 0, sizeof(dp));
	
	
	for(int i = 1; i <= n; i++) {
		// �ֹ��� �ڿ������� ó���Ͽ�, ���� �ֹ��� �ߺ� ó���ϴ� ���� ����
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= c; k++) {
				if(j >= chee[i] && k >= pota[i]){
				  dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - chee[i]][k - pota[i]] + 1);	
				} else {
				  dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}
	
	cout << dp[n][m][c] << '\n';
	
	
	return 0;
}
