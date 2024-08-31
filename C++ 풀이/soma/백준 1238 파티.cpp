#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> reGraph[1001];
int dist[1001]; // 최단거리 테이블
int reDist[1001];
int cnt = 0;

void solve(int s, vector<pair<int, int>> graph[1001], int dist[1001]) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  dist[s] = 0;

  while(pq.size()) {
    int d = pq.top().first; // 현재 비용
    int now = pq.top().second; // 현재 노드 위치
    pq.pop();

    if (dist[now] < d) continue;

    for(int i = 0; i < graph[now].size(); i++) { // 현재 노드에 연결된 모든 노드 반복 검사
      int next = graph[now][i].first;
      int cost = d + graph[now][i].second;
      // 현재 비용 + 새로운 비용
      if(cost < dist[next]) {
        // 계산한 비용이 기존 비용보다 낮으면 갱신
        dist[next] = cost;
        pq.push({cost, next});
        // 갱신한 값과 노드를 다시 넣고 반복
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
    // a노드, b노드, 비용
  }

    solve(x, reGraph, reDist);
  solve(x, graph, dist);

  for(int i = 1; i <= n; i++) {
    cnt = max(cnt, dist[i] + reDist[i]);
  }

  cout << cnt << '\n';

    return 0;
}
