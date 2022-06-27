#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[1030][1030];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, num;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> num;
			dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + num;
		}
	}
	
	int x1, y1, x2, y2;
	
	for(int i=0; i<m; i++){
		cin >> y1 >> x1 >> y2 >> x2;
		// 1번, 2번, 3번, 4번  2 3번은 겹쳐서 4번을 한 번 더 해줘야함 
		cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << '\n';

	}
	return 0;
}
