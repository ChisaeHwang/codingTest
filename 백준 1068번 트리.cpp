#include <bits/stdc++.h>

using namespace std;

int n, r, temp, root;
vector<int> adj[51];

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int sum : adj[here]) {
		if (sum == r) continue;
		ret += dfs(sum);
		child++;
	}
	if (child == 0) {
		return 1;
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	
	cin >> r; // ���� �� 
	
	if (r == root) { // �ֻ����� ��Ʈ��尡 ������� �׳� 0 ��� 
		cout << 0 << '\n';
	} else {
		cout << dfs(root) << '\n';	
	}
	
	return 0;
}
