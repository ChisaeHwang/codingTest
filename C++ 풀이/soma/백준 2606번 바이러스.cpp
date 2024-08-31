#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, ret; 
vector<int> v[101];
int visited[101];

void bfs(int num) {
	visited[num] = 1;
	for (int i = 0; i < v[num].size(); i++) {
		int next = v[num][i];
		if (visited[next]) continue;
		visited[next] = 1;
		bfs(next);
		ret++;
	}
	
	return;
}

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs(1);
	
	cout << ret << '\n';
	
	
	return 0;
}
