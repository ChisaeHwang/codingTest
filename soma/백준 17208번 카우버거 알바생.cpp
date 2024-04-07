#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dp[301][301]; // 치즈버거, 감자튀김 갯수에 따른 최댓값 
int chee[301];
int pota[301];


int main() {
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> chee[i] >> pota[i];
	}
	
    memset(dp, 0, sizeof(dp));
	
	for(int a = 0; a < n; a++) {
		// 주문을 뒤에서부터 처리하여, 같은 주문을 중복 처리하는 것을 방지
		for(int i = m; i >= chee[a]; i--) {
			for(int j = k; j >= pota[a]; j--) {
				dp[i][j] = max(dp[i][j], dp[i - chee[a]][j - pota[a]] + 1);
			}
		}
	}
	
	cout << dp[m][k] << '\n';
	
	
	return 0;
}
