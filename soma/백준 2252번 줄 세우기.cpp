#include <bits/stdc++.h>

using namespace std;

int n, m;


int main() {
	
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> degree(n + 1, 0);
	
	for (int  i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // a�� b���� �տ� ������ 
		degree[b]++; // B�� ������ ���� �߰� 
	}
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}
	
	while(q.size()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		
		for (auto &next : adj[now]) {
			--degree[next]; // ���� �� ���� �� ����
			if (degree[next] == 0) {
				q.push(next);
			} 
		}
	}
	
	
	
	return 0;
}
