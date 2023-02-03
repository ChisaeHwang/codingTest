#include <bits/stdc++.h> 
#define left _left
#define right _right

using namespace std;

const int MAX = 100001;
vector<int> a[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int dist[MAX];

struct Node {
 int left, right;
 int order, depth;
};

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	queue<int> q; 
	check[1] = true; // �湮 ���� 
	parent[1] = 0; // ���� �ƺ� ���� 
	q.push(1); // 1�� �־ ������ ���� 
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int y : a[x]){
			if(!check[y]){ // �湮 ������ �� 
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	
	for(int i=2; i<=n; i++){
		cout << parent[i] << '\n';
	}
	
	return 0;
}
