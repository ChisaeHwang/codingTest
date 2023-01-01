#include <bits/stdc++.h>

using namespace std;

int n, m, temp, INF = 987654321;
int dp[10001];

int main() {
	
	cin >> n >> m;
	fill(dp, dp + 10001, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = temp; j <= m; j++) {
			dp[j] = min(dp[j], dp[j - temp] + 1); // ��ȸ���� �Ź� �� ���� ������ ���ؾ��� 
			
		}		//   0 1 2 					Ƚ���� �߰��Ǵ� 1 ī��Ʈ �ϴ°��� 
	}			// 1 0 1 2   ->  min(dp[i], dp[i-2] + 1) -> min[2, 1] �̷������� ���������� ���ڸ� ��� ���ε� 
 				// 2 0 0 1
 				
				
	// �ּڰ��� �׻� �ִ��� ����� ������ �� 
	if(dp[m] == INF) cout << -1 << '\n';
	else cout << dp[m] << '\n';
	
	
	return 0;
}
