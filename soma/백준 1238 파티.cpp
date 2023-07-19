#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> reGraph[1001];
int dist[1001]; // �ִܰŸ� ���̺�
int reDist[1001];
int cnt = 0;

void solve(int s, vector<pair<int, int>> graph[1001], int dist[1001]) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  dist[s] = 0;

  while(pq.size()) {
    int d = pq.top().first; // ���� ���
    int now = pq.top().second; // ���� ��� ��ġ
    pq.pop();

    if (dist[now] < d) continue;

    for(int i = 0; i < graph[now].size(); i++) { // ���� ��忡 ����� ��� ��� �ݺ� �˻�
      int next = graph[now][i].first;
      int cost = d + graph[now][i].second;
      // ���� ��� + ���ο� ���
      if(cost < dist[next]) {
        // ����� ����� ���� ��뺸�� ������ ����
        dist[next] = cost;
        pq.push({cost, next});
        // ������ ���� ��带 �ٽ� �ְ� �ݺ�
      }
    }
  }
  
}

int main() {

  cin >> n >> m >> x;

  fill(dist, dist + 1001, INF);
  fill(reDist, reDist + 1001, INF);

  for(int i = 0; i < m; i++) {
    int a, b , c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    reGraph[b].push_back({a, c});
    // a���, b���, ���
  }

    solve(x, reGraph, reDist);
  solve(x, graph, dist);

  for(int i = 1; i <= n; i++) {
    cnt = max(cnt, dist[i] + reDist[i]);
  }

  cout << cnt << '\n';

    return 0;
}
