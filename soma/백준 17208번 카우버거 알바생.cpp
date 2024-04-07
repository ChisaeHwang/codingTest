#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dp[301][301]; // ġ�����, ����Ƣ�� ������ ���� �ִ� 
int chee[301];
int pota[301];


int main() {
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> chee[i] >> pota[i];
	}
	
    memset(dp, 0, sizeof(dp));
	
	for(int a = 0; a < n; a++) {
		// �ֹ��� �ڿ������� ó���Ͽ�, ���� �ֹ��� �ߺ� ó���ϴ� ���� ����
		for(int i = m; i >= chee[a]; i--) {
			for(int j = k; j >= pota[a]; j--) {
				dp[i][j] = max(dp[i][j], dp[i - chee[a]][j - pota[a]] + 1);
			}
		}
	}
	
	cout << dp[m][k] << '\n';
	
	
	return 0;
}
