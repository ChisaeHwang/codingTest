#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
int Fdist[4001];
int Wdist[2][4001];

void Fdij() {

	priority_queue<pair<int, int>> pq;
               
    pq.push({0, 1}); //비용, 노드 
    Fdist[1] = 0;
    
    while(pq.size()) {
    	int cost = -pq.top().first;
    	int now = pq.top().second;
    	pq.pop();
    	
    	if(Fdist[now] < cost) continue;
    	
    	for(int i = 0; i < adj[now].size(); i++) {
    		int next = adj[now][i].first;
			int next_cost = cost + adj[now][i].second;
			
			if(Fdist[next] > next_cost) {
				Fdist[next] = next_cost;
				pq.push({-next_cost, next});
 			} 	
		}
    	
	}

}

void Wdij() {
	priority_queue<pair<int, pair<int, int>>> pq; // cost, node, state
               
    pq.push({0, {1, 1}}); // 1 : run | 0 : walk
    
    while(pq.size()) {
    	int cost = -pq.top().first;
    	int now = pq.top().second.first;
    	int state = pq.top().second.second;
    	pq.pop();
    	
    	if(Wdist[(state + 1) % 2][now] < cost) continue;
    	
    	for(int i = 0; i < adj[now].size(); i++) {
    		
    		if(state == 1) { // run
    			int next = adj[now][i].first;
    			int next_cost = cost + adj[now][i].second / 2; // 여기서 /2를 해줘야합니다.
    			if(Wdist[1][next] > next_cost) { // 다음 상태는 0 (walk)
    				Wdist[1][next] = next_cost;
    				pq.push({-next_cost, {next, 0}});
				}
			} else if(state == 0) { // walk
				int next = adj[now][i].first;
    			int next_cost = cost + adj[now][i].second * 2; // 여기서 *2를 해줘야합니다.
    			if(Wdist[0][next] > next_cost) { // 다음 상태는 1 (run)
    				Wdist[0][next] = next_cost;
    				pq.push({-next_cost, {next, 1}});
				}
			}
		}
	}
}


int main() {
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
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
