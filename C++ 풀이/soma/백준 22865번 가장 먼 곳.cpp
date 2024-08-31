#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int n, m;
int a, b ,c;
vector<pair<int, int>> adj[100011];

vector<int> dij(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(100011, INF);
    dist[s] = 0;
    pq.push({0, s});
    // cost, node
    
    while(pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < cost) continue;
        
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int next_cost = cost + adj[now][i].second;
            
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
    
    cin >> n;
    
    cin >> a >> b >> c;
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
    	int from, to, cost;
    	cin >> from >> to >> cost;
    	adj[from].push_back({to, cost});
    	adj[to].push_back({from, cost});
	}
	
	vector<vector<int>> v;

    v.push_back(dij(a)); 
    v.push_back(dij(b));  
    v.push_back(dij(c));  
    
    int dist = -1;
    int ret = 0;
    
    for(int i = 1; i <= n; i++) {
    	if(i == a || i == b || i == c) continue;
    	
    	int len = min(v[0][i], min(v[1][i], v[2][i]));
    	if(dist < len) { // 최솟값중에 최댓값 구하기 
    		dist = len;
    		ret = i;
		}
	}
	
	cout << ret << '\n';
    
    
    return 0;
}

