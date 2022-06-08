#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// degree : 정도
// 그래프 저장 방법 ( 효율에 문제가 생김 
// 1. 인접 행렬 O( V²)     -> 한 정점 X와 연결된 간선을 
// 2. 인접 리스트 O(E) 차수             효율적으로 찾는 구조 
// 2-1. 링크드 리스트나 길이를 "동적"으로 변경할 수 있는 배열 사용 ex) vector
// 2-2 인접 리스트가 공간 복잡도 및 시간 복잡도가 더 작다 ( 거의 이거만 사용함 ) 
// 한 정점과 연결된 모든 간선을 찾는 시간   /                ->(V, E) 간선 있는지 여부 제외

// + 간선 리스트, 라이브러리 사용 불가능일 경우 사용유효 

bool a[2000][2000]; // 인접 행렬 
vector<int> g[2000]; // 인접 리스트 
vector<pair<int, int>> edges; // 간선 리스트 

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int from, to;
		cin >> from >> to;
		edges.push_back({from, to});
		edges.push_back({to, from});
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	
	m *= 2; // 친 구관계는 양방향이기에 간선의 갯수는 두배 
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			// A -> B 간선 리스트 
			int A = edges[i].first;
			int B = edges[i].second;
			// C -> D
			int C = edges[j].first;
			int D = edges[j].second;
			if(A == B || A == C || A == D || B == C || B == D || C == D){
				continue;
			}
			
			// B -> C 인접 행렬 
			if(!a[B][C]){
				continue;
			}
			
			// D -> E 인접 리스트 
			for(int E : g[D]){
				if(A == E || B == E || C == E || D == E){
					continue;
				}
				
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	
	cout << 0 << '\n';
	
	return 0;
} 
