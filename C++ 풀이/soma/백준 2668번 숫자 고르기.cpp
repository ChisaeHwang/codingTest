#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int arr[101];
int visited[101];
int ret[101];

void dfs(int cur, int prev) {
	
	if (visited[cur]) {
		if (cur == prev) {
			ret[cnt++] = cur;	
		}
	} else {
		visited[cur] = 1;
		dfs(arr[cur], prev);
	}
}

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	
    cout << cnt << '\n';
    
    for (int i = 0; i < cnt; i++) {
    	cout << ret[i] << '\n';
	}
	
	
	return 0;
}
