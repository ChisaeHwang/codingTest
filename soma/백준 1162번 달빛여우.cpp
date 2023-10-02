#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
int Fdist[4001];
int Wdist[2][4001];

void Fdij() {

	priority_queue<pair<int, int>, 
               vector<pair<int, int>>, 
               greater<pair<int, int>>> pq;
               
    pq.push({0, 1}); //비용, 노드 
    Fdist[1] = 0;
    
    while(pq.size()) {
    	int now = pq.top().second;
    	int cost = pq.top().first;
    	pq.pop();
    	
    	if(Fdist[now] < cost) continue;
    	
    	for(int i = 0; i < adj[now].size(); i++) {
    		int next = adj[now][i].first;
			int next_cost = cost + adj[now][i].second;
			
			if(Fdist[next] > next_cost) {
				Fdist[next] = next_cost;
				pq.push({next_cost, next});
 			} 	
		}
    	
	}

}

void Wdij() {
	
	priority_queue<pair<int, pair<int, int>>, 
               vector <pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> pq; // cost, node, state
               
    pq.push({0, {1, 1}}); // 1 : run | 0 : walk
    
    while(pq.size()) {
    	int cost = pq.top().first;
    	int now = pq.top().second.first;
    	int state = pq.top().second.second;
    	pq.pop();
    	
    	if(Wdist[(state + 1) % 2][now] < cost) continue;
    	
    	for(int i = 0; i < adj[now].size(); i++) {
    		
    		if(state == 1) {
    			int next = adj[now][i].first;
    			int next_cost = cost + adj[now][i].second / 2;
    			if(Wdist[1][next] > next_cost) {
    				Wdist[1][next] = next_cost;
    				pq.push({next_cost, {next, 0}});
				}
			} else if(state == 0) {
				int next = adj[now][i].first;
    			int next_cost = cost + adj[now][i].second * 2;
    			if(Wdist[0][next] > next_cost) {
    				Wdist[0][next] = next_cost;
    				pq.push({next_cost, {next, 1}});
				}
			}
		}
    	
	}
    
	
}

int main() {
	
	cin >> n >> m;
	
	adj.resize(n + 1);
	
	for(int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({to, cost * 2});
		adj[to].push_back({from, cost * 2});
	}
	
	fill(Fdist, Fdist + 4001, INF);
	
	 for(int i = 0; i < 2; i++) {
        fill(Wdist[i], Wdist[i] + 4001, INF);
    }
	
	Fdij();
	Wdij();
	
	int cnt = 0;
	
	for(int i = 2; i <= n; i++) {
		int Fsum = Fdist[i];
		int Wsum = min(Wdist[0][i], Wdist[1][i]);
		
		if(Fsum < Wsum) cnt++;
	}
	
	cout << cnt << '\n';
	
	
	return 0;
}
