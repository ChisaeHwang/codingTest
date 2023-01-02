#include <bits/stdc++.h>

using namespace std;

// dp[돈] = 최대 칼로리 

int dp[10001];
int c, m1, m2, p;

int main() {
	
	while(true) {
		int n, m1, m2;
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) break;
		int cnt = m1 * 100 + m2;
		fill(dp, dp + 10001, 0); // <- 이부분 
		for (int i = 0; i < n; i++) {
			scanf("%d %d.%d", &c, &m1, &m2);
			p = m1 * 100 + m2;
			for (int j = p; j <= cnt; j++) {
				dp[j] = max(dp[j], dp[j - p] + c); 
			}
			
//			한개까지밖에 사용 못하는 경우엔 이렇게 해야함 (누적합 없을 경우) 
//			for (int j = cnt; j >= p; j=--) { // 어차피 다 0이 나오기 때문에 누적이 없음 
//				dp[j] = max(dp[j], dp[j - p] + c);
//			}
			
			
		}
		
		cout << dp[cnt] << '\n';
	}
	
	
	return 0;
}
