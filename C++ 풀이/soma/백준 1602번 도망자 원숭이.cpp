#include <bits/stdc++.h>
#define MAX 501
#define INF 1e7

using namespace std;

int n, m, t;
int graph[MAX][MAX];
int dist[MAX]; 
int max_dog[MAX][MAX];
vector<pair<int, int>> dogs;

int main() {
	
	cin >> n >> m >> t;
	
	for(int i = 1; i <= n; i++) {
		fill(graph[i], graph[i] + n + 1, INF);
		fill(max_dog[i], max_dog[i] + n + 1, 0);
		graph[i][i] = 0; // 본인은 가중치 X 
	}
	
	for(int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		dist[i] = cost;
		dogs.push_back({ dist[i], i });
	}
	
	
	sort(dogs.begin(), dogs.end());
	
	for(int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from][to] = cost;
		graph[to][from] = cost;
		max_dog[from][to] = max(dist[from], dist[to]);
        max_dog[to][from] = max_dog[from][to];
	}
	
	for(int k = 0; k < n; k++){
		int mid = dogs[k].second;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				int middleTease = max(max_dog[i][mid], max_dog[mid][j]);
				int directTease = max_dog[i][j];

				// mid경유 비용 + mid지점 거칠때 괴롭힘 < 직진 경유 비용 + 직진일 때 괴롭힘
				if (graph[i][mid] + graph[mid][j] + middleTease < graph[i][j] + directTease) {
					graph[i][j] = graph[j][i] = graph[i][mid] + graph[mid][j];
					max_dog[i][j] = max_dog[j][i] = middleTease;
				}
			}
		}
	}
	
   for(int i = 0; i < t; i++) {
        int from, to;
        cin >> from >> to;
        if(graph[from][to] == INF) {
            cout << "-1" << '\n';
        } else {
            cout << graph[from][to] + max_dog[from][to] << '\n';
        }
    }
	
	
	return 0;
}
