#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;

vector<int> dij(int s) {

	priority_queue<pair<int, int>, 
	vector<pair<int, int>>, 
	greater<pair<int, int>>> pq;
	// cost, node
	
	vector<int> dist(adj.size(), INT_MAX); // �ʱ�ȭ
	
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
		int dist_gh = dist_g[h]; // ������ ���̿� ���� �Ȱ��Ƽ� �ϳ��� �־ �� 
		
		for(int i = 0; i < t; i++) {
			cin >> dest[i]; // �ĺ��� �Է� 
		}
		
		sort(dest.begin(), dest.end());
		
		for(int idx : dest) {
			// "�ִܰŸ�" �˰��� �̱⿡ ��ȸ�� ����
			// �� g -> h �� h -> g�� ������ �������̴�
			// �׷� �� ���� �׳� ���ͽ�Ʈ��� "�ִܰŸ�" �̱⿡ ������ ���ƾ��� �Ÿ���
			// �ٽ� �������� ��Ŀ�� ���������� "��ȸ�� ����" 
			if(dist_s[idx] == dist_s[g] + dist_gh + dist_h[idx]) cout << idx << " ";
			else if (dist_s[idx] == dist_s[h] + dist_gh + dist_g[idx]) cout << idx << " ";
		}
		cout << '\n';
	}		
	
    
    return 0;
}
