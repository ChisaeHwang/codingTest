#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 너비 우선 탐색 BFS (Breadth-First Search) 
// BFS 모든 가중치가 1일 때 최단 거리를 구할 수 있어 중요함 
 
int main() {
	
	// BFS의 구현은 큐를 이용해서 할 수 있다. (인접 행렬)
	queue<int> q;
	check[1] = true; q.push(1); // 시작점 
	while(!q.empty()){ // 큐가 비어 있지 않은 동안 
		int x = q.front();
		q.pop(); // 현재점 X 빼기 
		for(int i=1; i<=n; i++){
			if(a[x][i] == 1 && check[i] == false){  // 간선이 있고 방문한 적이 없을 경우 
				check[i] = true;
				q.push(i);
			}
		} 
	}
	
	// 인접 리스트
	
	while(!q.empty()){ // 큐가 비어 있지 않은 동안 
		int x = q.front();
		q.pop(); // 현재점 X 빼기 
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i]
			if(a[x][i] == 1 && check[i] == false){  // 간선이 있고 방문한 적이 없을 경우 
				checkyi] = true;
				q.push(y);
			}
		} 
	}
	
	return 0;
} 
