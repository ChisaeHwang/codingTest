#include <bits/stdc++.h>

using namespace std;

// Ʈ���� depth �̿��ؼ� Ǯ�� �� �� ���� 
// inorder ����ؾ��� 
 
vector<pair<int, int>> node[10001];
int n, a, b, c;
int visited[10001];
int result, endPoint;

vod bfs(int p, int depth) { // ����Ʈ�� ����
	
	if (visited[p]) return // �湮�� ��Ʈ ���� 
	
}
 

int main() {

	cin >> n; 
	
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c; // ����, ����ġ 
		node[a].push_back({b, c}); // ����ġ �ֱ� 
		node[b].push_back({a, c}); // ����ġ �ֱ� 
	}
	 
	
	
	
	
	return 0;
}
