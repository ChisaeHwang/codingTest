#include <bits/stdc++.h>

using namespace std;

int n, ret = 987654321;
vector<int> adj[101];
vector<int> result;
int visited[101];
int dist[101];

void bfs(int n) {
	queue<int> q;
	visited[n] = 1;
	q.push(n);
	
	while(q.size()) {
		int cur = q.front();
		q.pop();
		
		for (int next : adj[cur]) {
			if (visited[next]) continue;  
			dist[next] = dist[cur] + 1; // 회원 점수 더하기 
			visited[next] = 1; // 아는 회원이 적을 수록 더 많이 순회 
			q.push(next);	 // 그러므로 점수가 높아짐 
		}
	}
}

int main() {
	
	cin >> n;
	
	while(true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited)); 
		memset(dist, 0, sizeof(dist)); 
		
		bfs(i);
		
		int temp = 0;
		
		for (int j = 1; j <= n; j++) {
			if(i == j) continue; // 본인과 같은 간선은 없음 
			temp = max(temp, dist[j]); // i번 회원의 최대 점수 
			cout << dist[j] << " ";
		}
		
		cout << '\n';
		
		if (temp < ret) { // 회장 최소  점수 갱신 
			ret = temp;
			result.clear();
			result.push_back(i);
		} else if (temp == ret) { // 같은 점수 푸쉬 
			result.push_back(i);
		}
	}
	
	cout << ret << " " << result.size() << '\n';
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	
	return 0;
}
