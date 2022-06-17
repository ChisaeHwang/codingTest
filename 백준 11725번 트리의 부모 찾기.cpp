#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#define left _left
#define right _right

using namespace std;

const int MAX = 100111;
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
	for(int i=0; i<n; i++){
		int u, v, w;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	queue<int> q; 
	depth[1] = 0; // 루트에서 탐색 
	check[1] = true; // 방문 여부 
	parent[1] = 0; // 엄마 아빠 여부 
	q.push(1); // 1을 넣어서 시작점 설정 
	
	while(!q.empty()){
		int x = q.front(); // 현재 정점 빼주기 
		q.pop();
		for(int y : a[x]){
			if(!check[y]){ // 방문 안했을 때 
				depth[y] = depth[x] + 1; //  
				check[y] = true; // 방문하고 
				parent[y] = x; // parent는 x -> y 이다 
				q.push(y); // 큐에 넣어주기 
			}
		}
	}
	
	for(int i=2; i<=n; i++){
		cout << parent[i] << '\n';
	}
	
	return 0;
}
