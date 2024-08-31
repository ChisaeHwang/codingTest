#include <bits/stdc++.h>

using namespace std;

int n, k, temp;
int dp[101][10001]; // i��° ������ j��°���� ���µ� �ʿ��� �ּҰ��� 
int cost[101];
int INF = 987654321;

int go(int cnt, int sum) {
	if (cnt == n) { // �������ڸ��� �� base case 
		if (sum == 0) {
			return 0;
		} else {
			return INF;
		}
	}
	
	int ret = go(cnt + 1, sum); // �ƹ��͵� ���ϰ� count
	if (sum >= cost[cnt]) { // �� ũ�� �ȵǱ⿡ 
		ret = min(ret, go(cnt, sum - cost[cnt]) + 1);
	} 
	dp[cnt][sum] = ret;
	
	return ret;
}

int main() {	

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	
	int ret = go(0, k); // 0 -> k ����
	
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n'; 

	
	return 0;
}
