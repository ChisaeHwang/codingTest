#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[10001];
bool check[10001];
int dist[10001];
void bfs(int start) {
    memset(dist,0,sizeof(dist)); // 거리 
    memset(check,false,sizeof(check)); // 방문 
    queue<int> q;
    check[start] = true; // 방문 
    q.push(start);
    while (!q.empty()) {
        int x = q.front(); // 합 
        q.pop(); // X ->
        for (int i=0; i<a[x].size(); i++) {
            Edge &e = a[x][i];
            if (check[e.to] == false) {
                dist[e.to] = dist[x] + e.cost; // 거리 
                q.push(e.to); // 큐 
                check[e.to] = true; // 방문 
            }
        }
    }
}
int main() {
    int n;
    
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(Edge(v,w));
        a[v].push_back(Edge(u,w));
    }
    
    bfs(1);
    
    int start = 1;
    for (int i=2; i<=n; i++) {
        if (dist[i] > dist[start]) {
            start = i; // 거리가 가장 먼 정점 
        }
    }
    
    bfs(start);
    
    int ans = dist[1];
    for (int i=2; i<=n; i++) {
        if (ans < dist[i]) { // 거리가 가장 먼거 구하기 
            ans = dist[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
