#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, start, endP;

vector<int> solve(vector<vector<pair<int, int>>> &graph, int start) {
	
	vector<int> dist(n + 1, INF); // 각 도시의 최단거리 
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({0, start});
	
	while(pq.size()) {
		int d = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < d) continue; // 중복 체크
		
		for(int i = 0; i < graph[now].size(); i++) {
			int nNow = graph[now][i].first;
			int nDist = d + graph[now][i].second;
			
			if(nDist < dist[nNow]) { // 방문 안했을 경우 
				dist[nNow] = nDist;
				pq.push({nDist, nNow});
			}
		} 
		
	}
	
	return dist;
}

int main() {
	
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> graph(n + 1); // 기본 도화지
	
	for(int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({to, cost});
	}
	
	cin >> start >> endP;
	
	vector<int> dist = solve(graph, start);
	
	if(dist[endP] == INF)  // 출발 도시에서 도착 도시까지 갈 수 없는 경우
    	cout << "INF" << '\n';
	else  // 출발 도시에서 도착 도시까지의 최소 비용을 출력
    	cout << dist[endP] << '\n';
	
	
	return 0;
}
