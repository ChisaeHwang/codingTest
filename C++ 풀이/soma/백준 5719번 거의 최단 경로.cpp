#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int n, m, s, d;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> pre;
int visited[501][501];

int dij() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(505, INF);
    dist[s] = 0;
    pq.push({0, s});
    
    while(pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < cost) continue;
        
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int next_cost = cost + adj[now][i].second;
            
            if(visited[now][next]) continue;
            
            if(dist[next] == next_cost) {
                pre[next].push_back(now);   
            } else if(dist[next] > next_cost) {
                pre[next].clear();
                pre[next].push_back(now);
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }   
        }
    }
    
    return dist[d] == INF ? -1 : dist[d];
}

void solve(int cur) {
    for(auto a : pre[cur]) {
        for(int i = 0; i < adj[a].size(); i++) {
            if(adj[a][i].first == cur && !visited[a][cur]) {
                visited[a][cur] = 1;
                solve(a);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {

        cin >> n >> m;
        
        if(n == 0 && m == 0) break;
        
        cin >> s >> d;
        
        adj = vector<vector<pair<int, int>>>(n + 1);  // adj 초기화
        pre = vector<vector<int>>(n + 1);  // pre 초기화
        memset(visited, 0, sizeof visited);
            
        
        for(int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            adj[from].push_back({to, cost});
        }
        
        dij();
        solve(d);
        int ret = dij();
        
        cout << ret << '\n';
    }
    
    return 0;
}

