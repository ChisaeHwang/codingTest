#include <bits/stdc++.h>

using namespace std;

int v, e;
int graph[401][401];
const int INF = 987654321; 

int main() {
	
	cin >> v >> e;
	
	for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            graph[i][j] = INF;
        }
    }
	
	// �ڱ� �ڽſ� ���� �Ÿ��� 0���� �ʱ�ȭ�մϴ�.
    for (int i = 0; i < v; ++i) {
        graph[i][i] = 0;
    }
	
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = c;
	}
	
	// �÷��̵� �ͼ� 
	int cycle = INF;
	
	for (int k = 0; k < v; k++) { // k�� ������ ���� ���� ��� 
		for (int i = 0; i < v; i++) { // ���� ���� 
			for (int j = 0; j < v; j++) { // ���� ���� 
				if(graph[i][k] != INF && graph[k][j] != INF // �̹� ��ΰ� �ִ��� 
				&& graph[i][k] + graph[k][j] < graph[i][j]){ // �ִ� ����� �� �۾ƾ� �� 
					graph[i][j] = graph[i][k] + graph[k][j];
				} 
			}
		}	
	}
	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (graph[i][j] != INF && graph[j][i] != INF && i != j) {
				cycle = min(cycle, graph[i][j] + graph[j][i]);
			}
		}
	}
	
	if (cycle == INF) {
		cout << -1 << '\n';
	} else {
		cout << cycle << '\n';
	}

	
	return 0;
}
