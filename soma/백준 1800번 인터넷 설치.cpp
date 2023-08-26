#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, p;
vector<vector<pair<int, int>>> adj; // 노드, 거리 
vector<pair<int, pair<int, int>>> edges; // ((from, to), cost)


vector<int> dij(int start, int n) {
	
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	
	priority_queue<pair<int, int>, 
	vector<pair<int, int>>, 
	greater<pair<int, int>>> pq;
	
	pq.push({0, start}); // 거리, 노드번호
	
	while(pq.size()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < cost) continue; // 이미 더 짧은 경로가 있을 경우 
		
		for(int i = 0; i < adj[now].size(); i++) {
			int to = adj[now][i].first; // 다음 노드
			int next = cost + adj[now][i].second; // 다음 경로 값 
			
			if(dist[to] > next) { // 더 짧은 경로일 경우 
				dist[to] = next;
				pq.push({next, to}); // 현재까지 거리, 다음 노드 
			} 
		}
		
	} 
	
	return dist;
}

int main() {
	
	cin >> n >> m >> p;
	
	adj.resize(n + 1);  // adj의 크기를 n + 1로 초기화
	pre.resize(n + 1, -1);

	
	for(int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
	
		edges.push_back({cost, {from, to}});
	}	
	
	sort(edges.begin(), edges.end()); 
	
	for(int i = 0; i < m - p; i++) {
		int cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		
		adj[from].push_back({to, cost});
		adj[to].push_back({from, cost});
	}
	
	vector<int> ret = dij(1, n);
	vector<int> path = traceback(1, n);
    
    int maxCost = -1;
    for(int i = 1; i < path.size(); i++) {
        int from = path[i-1];
        int to = path[i];
        for(auto& edge : adj[from]) {
            if(edge.first == to) {
                maxCost = max(maxCost, edge.second);
                break;
            }
        }
    }
    
    cout << maxCost << '\n';
	

	
	return 0;
}
