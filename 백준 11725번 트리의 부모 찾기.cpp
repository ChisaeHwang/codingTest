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
	depth[1] = 0; // ��Ʈ���� Ž�� 
	check[1] = true; // �湮 ���� 
	parent[1] = 0; // ���� �ƺ� ���� 
	q.push(1); // 1�� �־ ������ ���� 
	
	while(!q.empty()){
		int x = q.front(); // ���� ���� ���ֱ� 
		q.pop();
		for(int y : a[x]){
			if(!check[y]){ // �湮 ������ �� 
				depth[y] = depth[x] + 1; //  
				check[y] = true; // �湮�ϰ� 
				parent[y] = x; // parent�� x -> y �̴� 
				q.push(y); // ť�� �־��ֱ� 
			}
		}
	}
	
	for(int i=2; i<=n; i++){
		cout << parent[i] << '\n';
	}
	
	return 0;
}
