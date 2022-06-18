#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[3000];
int check[3000];
int dist[3000];

// p -> x -> y
int go(int x, int p){
	// -2: 사이클 찾음(포함 X),  -1: 사이클 못 찾음, 0~n-1: 사이클 찾음, 시작 인덱스
	if(check[x] == 1) return x; // 시작 인덱스 
	check[x] = 1; 
	for(int y : a[x]){
		if(y == p) continue; // 이전 정점과 같은 정점이면 건너뛰기 
		// y -> x, x -> p 에 들어감 
		int res = go(y, x);
		if(res == -2) return -2; // 포함 안되는 사이클 -2 더하기 
		if(res >= 0){
			check[x] = 2;
			if(x == res) return -2; // 현재 정점이 사이클 시작점이랑 같음 
			else return res;
		}
	}
	
	return -1;
}

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	go(0, -1); // 순환선 2 사이클 
	queue<int> q;
	for(int i=0; i<n; i++){
		if(check[i] == 2){ // 체크 2 인거만 
			dist[i] = 0;
			q.push(i); // 순환선으로부터 떨어진 거리를 위해 
		} else { // 아직 구하지 못했으므로 -1 
			dist[i] = -1;
		}
	}
	
	// BFS 로 모든 정점 거리 구하기 
	while(!q.empty()){
		int x = q.front(); // 현재 정점 빼기 x -> y 
		q.pop();
		for(int y : a[x]){ 
			if(dist[y] == -1){ // 위에서 -1로 초기화 했기에 -1은 아직 방문한 정점이 아님 
				q.push(y); // 방문하고 
				dist[y] = dist[x] + 1; // 거리 업데이트 하고 
			}
		}
	}
	
	// 거리 출력 
	for(int i=0; i<n; i++){
		cout << dist[i] << ' ';
	}
	
	cout << '\n';
	
	return 0;
}  
