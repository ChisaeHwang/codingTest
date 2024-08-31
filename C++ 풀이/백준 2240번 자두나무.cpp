#include <bits/stdc++.h>

using namespace std;

int dp[1001][2][31]; // 자두 떨어지는 시간, 떨어지는 나무 번호, 움직이는 횟수 
int n, m;
int b[1001];

int go (int idx, int tree, int cnt) {
	if (cnt < 0) return -1e9; // 아래 로직에서 그냥 -1이 들어올 수 도 있기에 체크 
	if (idx == n) return 0;
	
	
	int &ret = dp[idx][tree][cnt];
	if (~ret) return ret; // ret != -1 대신 사용 가능 
	// ~ = -(n+1) 이다 
	
	
	// 움직이거나 안 움직이거나 
	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}			// 1의 ^ (XOR 연산자) 는 0이 됨, 0의 ^ (XOR 연산자)는 1이 됨 
			// if문을 없앨 수 있음 


int main() {
	
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	
	
	return 0;
}
