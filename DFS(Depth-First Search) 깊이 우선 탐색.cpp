#include <iostream>
#include <algorithm>
#include <stack> 

using namespace std;

// 깊이 우선 탐색 DFS (Depth-First Search)
// 재귀 함수를 이용해 구현 

// 인접 행렬을 이용한 구현 (2차원 배열) 
void dfs(int x){ // dfs(x) : x 를 방문 
	check[x] = true
	for(int i=1; i<=n; i++){
		if(a[x][i] == 1 && check[i] == false){ // 간선이 있고 방문한 적이 없을 경우 
			dfs(i);
		}
	}
}
// O( V²) 이다, 모든 정점을 다 순회해봐야 하기 때문에 
// dfs 하나 의 복잡도 : V -> V x O(V) = O( V²) 

// 인접 리스트를 이용한 구현 (1차원 배열) 
void dfs(int x){ // dfs(x) : x 를 방문 
	check[x] = true
	for(int i=0; i<=a[x].size(); i++){
		int y = a[x][i];
		if(check[y] == false){
			dfs(y);
		}	
	}
}
// O( V + E ) 이다, 차수를 다 더하면 간선의 갯수와 같기 때문 ( E : 차수 ) 

int main(){
	
	
	
	return 0;
}
