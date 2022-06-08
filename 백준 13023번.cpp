#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// degree : ����
// �׷��� ���� ��� ( ȿ���� ������ ���� 
// 1. ���� ��� O( V��)     -> �� ���� X�� ����� ������ 
// 2. ���� ����Ʈ O(E) ����             ȿ�������� ã�� ���� 
// 2-1. ��ũ�� ����Ʈ�� ���̸� "����"���� ������ �� �ִ� �迭 ��� ex) vector
// 2-2 ���� ����Ʈ�� ���� ���⵵ �� �ð� ���⵵�� �� �۴� ( ���� �̰Ÿ� ����� ) 
// �� ������ ����� ��� ������ ã�� �ð�   /                ->(V, E) ���� �ִ��� ���� ����

// + ���� ����Ʈ, ���̺귯�� ��� �Ұ����� ��� �����ȿ 

bool a[2000][2000]; // ���� ��� 
vector<int> g[2000]; // ���� ����Ʈ 
vector<pair<int, int>> edges; // ���� ����Ʈ 

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
	
	m *= 2; // ģ ������� ������̱⿡ ������ ������ �ι� 
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			// A -> B ���� ����Ʈ 
			int A = edges[i].first;
			int B = edges[i].second;
			// C -> D
			int C = edges[j].first;
			int D = edges[j].second;
			if(A == B || A == C || A == D || B == C || B == D || C == D){
				continue;
			}
			
			// B -> C ���� ��� 
			if(!a[B][C]){
				continue;
			}
			
			// D -> E ���� ����Ʈ 
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
