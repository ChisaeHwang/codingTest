#include <bits/stdc++.h>

using namespace std;

int dp[1001][2][31]; // �ڵ� �������� �ð�, �������� ���� ��ȣ, �����̴� Ƚ�� 
int n, m;
int b[1001];

int go (int idx, int tree, int cnt) {
	if (cnt < 0) return -1e9; // �Ʒ� �������� �׳� -1�� ���� �� �� �ֱ⿡ üũ 
	if (idx == n) return 0;
	
	
	int &ret = dp[idx][tree][cnt];
	if (~ret) return ret; // ret != -1 ��� ��� ���� 
	// ~ = -(n+1) �̴� 
	
	
	// �����̰ų� �� �����̰ų� 
	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}			// 1�� ^ (XOR ������) �� 0�� ��, 0�� ^ (XOR ������)�� 1�� �� 
			// if���� ���� �� ���� 


int main() {
	
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	
	
	return 0;
}
