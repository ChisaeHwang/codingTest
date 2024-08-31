#include <bits/stdc++.h>

using namespace std;

// 트리의 depth 이용해서 풀면 될 거 같다 
// inorder 사용해야함 
 
vector<pair<int, int>> node[10001];
int n, a, b, c;
int visited[10001];
int result, endPoint;

vod bfs(int p, int depth) { // 포인트랑 깊이
	
	if (visited[p]) return // 방문한 노트 리턴 
	
}
 

int main() {

	cin >> n; 
	
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c; // 간선, 가중치 
		node[a].push_back({b, c}); // 가중치 넣기 
		node[b].push_back({a, c}); // 가중치 넣기 
	}
	 
	
	
	
	
	return 0;
}
