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
		adj[a].push_back(b); // a가 b보다 앞에 서야함 
		degree[b]++; // B로 들어오는 간선 추가 
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
			--degree[next]; // 간선 수 적은 수 부터
			if (degree[next] == 0) {
				q.push(next);
			} 
		}
	}
	
	
	
	return 0;
}
