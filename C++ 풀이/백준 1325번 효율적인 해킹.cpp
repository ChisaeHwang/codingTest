#include <bits/stdc++.h>

using namespace std;

// ����� ���̰� ����� ��ǻ�͸� �������� �ȴ�

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
		memset(visited, 0, sizeof(visited)); // visited �Ź� �ʱ�ȭ *�߿� 
		arr[i] = dfs(i);
		result = max(result, arr[i]);
	}
	
	
	for (int i = 1; i <= n; i++){
		if (result == arr[i]) { // �������� ���� ��� 
			cout << i << " ";
		}
	}
	
	return 0;
} 
