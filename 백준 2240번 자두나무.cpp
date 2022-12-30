#include <bits/stdc++.h>

using namespace std;

int dp[1001][2][31]; // 자두 떨어지는 시간, 떨어지는 나무 번호, 움직이는 횟수 
int n, m;
int b[1001];

int go (int idx, int tree, int cnt) {
	if (cnt < 0) return -1e9; // 아래 로직에서 그냥 -1이 들어올 수 도 있기에 체크 
	if (idx == n) return cnt == 0 ? 0 : -1e9;
	
	
	int &ret = dp[idx][tree][cnt];
	if (~ret) return ret; // ret != -1 대신 사용 가능 
	// ~ = -(n+1) 이다 
	
	
	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}


int main() {
	
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	
	
	return 0;
}
