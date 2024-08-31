#include <bits/stdc++.h>

using namespace std;

int n, arr[101][101], visited[101];
string s;
vector<int> v[101];


void dfs(int list) {
	for (int i = 0; i < v[list].size(); i++) {
		if (visited[v[list][i]]) continue;
		visited[v[list][i]] = 1;
		dfs(v[list][i]);
	}
	
	return;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v[i].push_back(j);
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		memset(visited, 0, sizeof(visited));
		dfs(i);
		for (int j = 0; j < n; j++){
			cout << visited[j] << " ";
		}
		cout << '\n';
	}
	
	
	return 0;
}
