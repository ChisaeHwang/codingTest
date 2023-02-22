#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int visited[10]; 

void dfs(int cnt, int start) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = start; i <= n; i++) {
		arr[cnt] = i;
		dfs(cnt + 1, i);
	}
	
}

int main() {
	
	cin >> n >> m;
	
	dfs(0, 1);
	
	return 0;
}
