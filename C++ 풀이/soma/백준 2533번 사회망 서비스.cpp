#include <bits/stdc++.h>

using namespace std;

int dp[1000001][2]; 
// 본인 노드가 얼리 일 때 또는 얼리가 아닐 때, 최소 얼리어댑터의 개수
int MAX = 1000000;
int n, a, b;
vector<int> v[MAX];

void dfs(int node){
    isVisited[node] = 1;
    dp[node][0] = 0; // 본인이 얼리가 아니면 얼리 개수 0 
    dp[node][1] = 1; // 본인이 얼리면 얼리 개수 1 
    
    for(int i=0; i<edges[node].size(); i++){
        int conn_node = edges[node][i]; 
        
        if(isVisited[conn_node]) continue; // 아래로 DFS 진행하기 위해서 위로 이동 방지  
        
        dfs(conn_node);
        
        dp[node][0] += dp[conn_node][1]; // 현재 노드가 얼리가 아니라면, 주변 노드는 얼리어야 한다. 
        dp[node][1] += min(dp[conn_node][0], dp[conn_node][1]); // 현재 노드가 얼리라면, 주변은 얼리 또는 얼리가 아니다. 
    }
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	
	return 0;
}
