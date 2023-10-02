#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
int Wdist[2][4001];

void dij() {

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



int main() {
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	

	
	
	return 0;
}
