#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;

vector<int> dij(int s) {

	priority_queue<pair<int, int>, 
	vector<pair<int, int>>, 
	greater<pair<int, int>>> pq;
	// cost, node
	
	vector<int> dist(adj.size(), INT_MAX); // 초기화
	
	dist[s] = 0;
	
	pq.push({0, s});
	
	while(pq.size()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < cost) continue;
		
		for(int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int next_cost = adj[now][i].second + cost;
			
			if(dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({next_cost, next});
			}
		}
	}
	
	return dist;
}

int main() {
    ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int t_c;
	
	cin >> t_c;
	
	while(t_c--) {
		int n, m, t;
		
		cin >> n >> m >> t;
		
		adj.clear();
		adj.resize(n + 1);
		vector<int> dest(t);
		
		int s, g, h;
		
		cin >> s >> g >> h;
		
		for(int i = 0; i < m; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			adj[from].push_back({to, cost});
			adj[to].push_back({from, cost});
		}
		
		vector<int> dist_s = dij(s);
		vector<int> dist_g = dij(g);
		vector<int> dist_h = dij(h);
		int dist_gh = dist_g[h]; // 어차피 사이에 값은 똑같아서 하나만 있어도 됨 
		
		for(int i = 0; i < t; i++) {
			cin >> dest[i]; // 후보지 입력 
		}
		
		sort(dest.begin(), dest.end());
		
		for(int idx : dest) {
			// "최단거리" 알고리즘 이기에 우회를 안함
			// 즉 g -> h 나 h -> g를 지나는 도착지이던
			// 그런 거 없이 그냥 다익스트라던 "최단거리" 이기에 무조건 같아야함 거리는
			// 다시 말하지만 서커스 예술가들은 "우회를 안함" 
			if(dist_s[idx] == dist_s[g] + dist_gh + dist_h[idx]) cout << idx << " ";
			else if (dist_s[idx] == dist_s[h] + dist_gh + dist_g[idx]) cout << idx << " ";
		}
		cout << '\n';
	}		
	
    
    return 0;
}
