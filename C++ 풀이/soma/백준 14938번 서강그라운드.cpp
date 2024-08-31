#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

vector<vector<pair<int, int>>> adj; 
vector<int> item;

vector<int> dij(int start, int n) {
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start}); // 거리, 노드번호
	
	while(pq.size()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < cost) continue;
		
		for(int i = 0; i < adj[now].size(); i++) {
			int to = adj[now][i].first; // 인접 노드
			int next = adj[now][i].second + cost;  // 새로운 경로의 값 
			
			if(dist[to] > next) {
				dist[to] = next;
				pq.push({next, to});
			}
		}
	} 
	
	return dist;
}

int main() {
	
	int n, m, r;
	
	cin >> n >> m >> r;
	
	item.resize(n);  // item 벡터 크기 초기화
	adj.resize(n + 1);  // adj 벡터 크기 초기화
	
	
	for(int i = 0; i < n; i++) {
		cin >> item[i];
	}
	
	for(int i = 0; i < r; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({to, cost});
		adj[to].push_back({from, cost});	
	}
	
	int ret = 0;
	
	for(int i = 1; i <= n; i++) {
		vector<int> dist = dij(i, n);
		int itemCnt = 0;
		for(int j = 0; j <= n; j++) {
			if(dist[j] <= m) {
				itemCnt += item[j-1];
			}
		}
		ret = max(ret, itemCnt);
	}
	
	cout << ret << '\n';
	
	
	return 0;
}
