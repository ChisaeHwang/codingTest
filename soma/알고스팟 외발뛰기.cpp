#include <bits/stdc++.h>

using namespace std;

int t, n, board[101][101];
int dp[101][101];

int jump(int y, int x) {
	
	if (y >= n || x >= n) return 0;
	// ������� 1 : board�� ���� ��� 
	if (y == n - 1 && x == n - 1) return 1;
	// ������� 2 : ������ ���
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	
	int size = board[y][x];
	
	return ret = (jump(y + size, x) || jump(y, x + size));
}

int main() {
	
	cin >> t;
	
	while(t--) {
		
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		
		memset(dp, -1, sizeof(dp));
		
		if (jump(0, 0)) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
		
	}
	
	return 0;
}
