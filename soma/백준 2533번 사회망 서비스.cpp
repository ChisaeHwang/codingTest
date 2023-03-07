#include <bits/stdc++.h>

using namespace std;

int dp[1000001][2]; 
// ���� ��尡 �� �� �� �Ǵ� �󸮰� �ƴ� ��, �ּ� �󸮾������ ����
int MAX = 1000000;
int n, a, b;
vector<int> v[MAX];

void dfs(int node){
    isVisited[node] = 1;
    dp[node][0] = 0; // ������ �󸮰� �ƴϸ� �� ���� 0 
    dp[node][1] = 1; // ������ �󸮸� �� ���� 1 
    
    for(int i=0; i<edges[node].size(); i++){
        int conn_node = edges[node][i]; 
        
        if(isVisited[conn_node]) continue; // �Ʒ��� DFS �����ϱ� ���ؼ� ���� �̵� ����  
        
        dfs(conn_node);
        
        dp[node][0] += dp[conn_node][1]; // ���� ��尡 �󸮰� �ƴ϶��, �ֺ� ���� �󸮾�� �Ѵ�. 
        dp[node][1] += min(dp[conn_node][0], dp[conn_node][1]); // ���� ��尡 �󸮶��, �ֺ��� �� �Ǵ� �󸮰� �ƴϴ�. 
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
