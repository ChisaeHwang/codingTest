#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int num[10];
int visited[10]; 

void dfs(int cnt) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		arr[cnt] = num[i];
		dfs(cnt + 1);
		visited[i] = 0;
	}
	
}

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	sort(num, num + n);
	
	dfs(0);
	
	return 0;
}
