#include <bits/stdc++.h>

using namespace std;

int n, m, c;

int dp[101][301][301]; // 주문, 치즈버거, 감자튀김 갯수에 따른 최댓값 
int chee[301];
int pota[301];


int main() {
	
	cin >> n >> m >> c;
	
	for(int i = 1; i <= n; i++) {
		cin >> chee[i] >> pota[i];
	}
	
    memset(dp, 0, sizeof(dp));
	
	
	for(int i = 1; i <= n; i++) {
		// 주문을 뒤에서부터 처리하여, 같은 주문을 중복 처리하는 것을 방지
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
