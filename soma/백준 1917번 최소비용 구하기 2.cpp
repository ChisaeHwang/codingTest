#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, start, endP;

vector<int> solve(vector<vector<pair<int, int>>> &graph, int start) {
	
	vector<int> dist(n + 1, INF); // �� ������ �ִܰŸ� 
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({0, start});
	
	while(pq.size()) {
		int d = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < d) continue; // �ߺ� üũ
		
		for(int i = 0; i < graph[now].size(); i++) {
			int nNow = graph[now][i].first;
			int nDist = d + graph[now][i].second;
			
			if(nDist < dist[nNow]) { // �湮 ������ ��� 
				dist[nNow] = nDist;
				pq.push({nDist, nNow});
			}
		} 
		
	}
	
	return dist;
}

int main() {
	
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> graph(n + 1); // �⺻ ��ȭ��
	
	for(int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({to, cost});
	}
	
	cin >> start >> endP;
	
	vector<int> dist = solve(graph, start);
	
	if(dist[endP] == INF)  // ��� ���ÿ��� ���� ���ñ��� �� �� ���� ���
    	cout << "INF" << '\n';
	else  // ��� ���ÿ��� ���� ���ñ����� �ּ� ����� ���
    	cout << dist[endP] << '\n';
	
	
	return 0;
}
