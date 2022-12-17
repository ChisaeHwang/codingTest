#include <bits/stdc++.h>

using namespace std;

// 노드의 길이가 가장긴 컴퓨터를 가져오면 된다

int n, m, a, b;
int arr[10001], visited[10001], result;
vector<int> v[10001]; 

int dfs(int here) {
	visited[here] = 1;
	int ret = 1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		ret += dfs(there);
	}
	return ret;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);  
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		v[b].push_back(a);  
	}
	
	for (int i = 1; i <= n; i++){
		memset(visited, 0, sizeof(visited)); // visited 매번 초기화 *중요 
		arr[i] = dfs(i);
		result = max(result, arr[i]);
	}
	
	
	for (int i = 1; i <= n; i++){
		if (result == arr[i]) { // 최종값이 같은 경우 
			cout << i << " ";
		}
	}
	
	return 0;
} 
