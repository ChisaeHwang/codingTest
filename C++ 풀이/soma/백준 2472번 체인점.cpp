#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
int pre[1001];
int check = 0;

int dij(int from, int to) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 데이터 타입, 컨테이너 지정(메모리 설정? 크기 설정), 정렬 기준 설정 (기본은 내림차순 greater는 오름차순) 
	vector<int> dist(1001, INF);
    dist[1] = 0;
    pq.push({0, 1});
    // cost, node
    
    while(pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < cost) continue;
        
        for(int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int next_cost = cost + adj[now][i].second;
            
            if(from == now && to == next || from == next && to == now) continue;
            
            if(dist[next] > next_cost) {
            	if(!check) {
            		pre[next] = now;	
				}
            	dist[next] = next_cost;
				pq.push({next_cost, next}); 	
			}
        }
    }
    
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
    	int from, to, cost;
    	cin >> from >> to >> cost;
    	adj[from].push_back({to, cost});
    	adj[to].push_back({from, cost});
	}
	
	int a = dij(0, 0);
	check = 1;
	pre[1] = 1;
	
	int ret = 0;
	
	
    for(int i = n; i != pre[i]; i = pre[i]) {
    	int to = i;
    	int from = pre[i];
    	int temp = dij(to, from);
    	if(temp > ret) {
    		ret = temp;
		}
	}
	
	cout << ret << '\n';
    
    return 0;
}

