#include <bits/stdc++.h>

using namespace std;

// dp[��] = �ִ� Į�θ� 

int dp[10001];
int c, m1, m2, p;

int main() {
	
	while(true) {
		int n, m1, m2;
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) break;
		int cnt = m1 * 100 + m2;
		fill(dp, dp + 10001, 0); // <- �̺κ� 
		for (int i = 0; i < n; i++) {
			scanf("%d %d.%d", &c, &m1, &m2);
			p = m1 * 100 + m2;
			for (int j = p; j <= cnt; j++) {
				dp[j] = max(dp[j], dp[j - p] + c); 
			}
			
//			�Ѱ������ۿ� ��� ���ϴ� ��쿣 �̷��� �ؾ��� (������ ���� ���) 
//			for (int j = cnt; j >= p; j=--) { // ������ �� 0�� ������ ������ ������ ���� 
//				dp[j] = max(dp[j], dp[j - p] + c);
//			}
			
			
		}
		
		cout << dp[cnt] << '\n';
	}
	
	
	return 0;
}
