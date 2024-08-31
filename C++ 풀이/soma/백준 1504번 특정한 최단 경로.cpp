#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, E;
int graph[801][801];

int solve(int start, int end) {
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	
	priority_queue<pair<int, int>, 
	vector<pair<int, int>>, 
	greater<pair<int, int>>> pq;
	
	pq.push({0, start});
	
	while(pq.size()) {
		int cost = pq.top().first;
		int from = pq.top().second;
		pq.pop();
		
		for(int to = 1; to <= N; to++) {
            	int next = cost + graph[from][to];

	            if(dist[to] > next) {
	                dist[to] = next;
	                pq.push({next, to});
	            }
		}
	}
    return dist[end];
}


int main() {
	
	cin >> N >> E;
	
	for(int i = 0; i <= N; i++) {
	    fill(graph[i], graph[i] + N + 1, INF);
	    graph[i][i] = 0;
	}
	
	for(int i = 0; i < E; i++) {
	    int from, to, cost;
	    cin >> from >> to >> cost;
	    graph[from][to] = cost;
	    graph[to][from] = cost;
	}
	
	int u, v;
	cin >> u >> v;
	
	 int start_to_u = solve(1, u);
    int start_to_v = solve(1, v);
    int u_to_v = solve(u, v);
    int u_to_N = solve(u, N);
    int v_to_N = solve(v, N);

    if(start_to_u >= INF 
	|| start_to_v >= INF 
	|| u_to_v >= INF 
	|| u_to_N >= INF 
	|| v_to_N >= INF) {
        cout << "-1\n";
    } else {
        cout << min(start_to_u + u_to_v + v_to_N, 
		start_to_v + u_to_v + u_to_N) << '\n';
    }

    return 0;
}


