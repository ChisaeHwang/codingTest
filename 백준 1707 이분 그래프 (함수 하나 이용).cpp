#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[20001];
int color[20001]; // 0, 1 : �湮�ϰ� �׷� ��ȣ1, 2 : �湮�ϰ� �׷� ��ȣ2 

// �̺� �׷����� true, �ƴϸ� false 
bool dfs(int node, int c){ // node �湮, �׷� ��ȣ : c�� 
	color[node] = c; 
	for(int i=0; i<a[node].size(); i++){
		int next = a[node][i];
		if(color[next] == 0){ // ���� �湮 �� �� 
			if(dfs(next, 3-c) == false){
				return false;
			} 
		} else if (color[next] == color[node]){ // �׷� ��ȣ�� ������ false, �̺� �׷����� �ƴ� 
				return false;
		}
	}
	
	return true;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			a[i].clear();
			color[i] = 0;
		}
		
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
		bool ok = true;
		
		for(int i=1; i<=n; i++){
			if(color[i] == 0){
				if(dfs(i, 1) == false){
					ok = false;
				}
			} 
		}

		if(ok){
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} 
	
	return 0;
}
