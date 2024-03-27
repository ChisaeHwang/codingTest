#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 5000;
vector<int> adj[MAX]; 
int dp[MAX];
bool visited[MAX]; 
int heights[MAX]; 

int dfs(int node) {

    if (dp[node] != -1) return dp[node];

    dp[node] = 1; 
    for (int next : adj[node]) {
        if (heights[node] < heights[next]) { 
            dp[node] = max(dp[node], dfs(next) + 1);
        }
    }

    return dp[node];
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
        dp[i] = -1; 
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        if (heights[u] < heights[v]) adj[u].push_back(v);
        else adj[v].push_back(u);
    }

    for (int i = 0; i < N; ++i) {
        cout << dfs(i) << "\n";
    }

    return 0;
}

