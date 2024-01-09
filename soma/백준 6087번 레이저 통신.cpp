#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

char arr[101][101];
int visited[101][101][4];
int dist[101][101][4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
pair<int, int> start, finish;

void bfs(int x, int y) {
	
	priority_queue<pair<pair<int, int>, int>, 
               vector<pair<pair<int, int>, int>>, 
               greater<pair<pair<int, int>, int>>> pq;


	pq.push({{x, y}, -1});
	// direction, x, y
	
	for(int i = 0; i < 4; i++) {
		visited[x][y][i] = 1;
		dist[x][y][i] = 0;
	}
	
	while(pq.size()) {
		int d = pq.top().second;
		int x = pq.top().first.first;
		int y = pq.top().first.second;
		pq.pop();
		
		for(int i = 0; i < 4; i++) { 
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if(arr[nx][ny] == '*') continue;
				if(d == i) { // ������ ���� ��� 
					if(!visited[nx][ny][i]) {
						dist[nx][ny][i] = dist[x][y][d];
						visited[nx][ny][i] = 1;
						pq.push({{nx, ny}, i});
					}
				 	else {
						if(dist[nx][ny][i] > dist[x][y][d]) {
							dist[nx][ny][i] = dist[x][y][d];
							pq.push({{nx, ny}, i});
						}
					}
				}
				else { // ������ �ٸ� ��� 
					if(!visited[nx][ny][i]) {
						dist[nx][ny][i] = dist[x][y][d] + 1; 
						visited[nx][ny][i] = 1;
						pq.push({{nx, ny}, i});
					}
				 	else {
						if(dist[nx][ny][i] > dist[x][y][d] + 1) {
							dist[nx][ny][i] = dist[x][y][d] + 1;
							pq.push({{nx, ny}, i});
						}
					}
				}
			} 	
		}
	}
}

int main() {
	
	cin >> m >> n;
	// W�� ���� ����� ��(����) ���� ������ ���� ���̰� ���� 
	// H�� ���� ����� ��(����) ���� ������ ���� ���̰� ���� 
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 'C' && start.first == 0) {
				 start = {i,j};
			}
			else if(arr[i][j] == 'C') {
				finish = {i,j};
			}
		}
	}
	
	bfs(start.first, start.second);
	int ret = INF;
	for(int i = 0; i < 4; i++) {
		if(visited[finish.first][finish.second][i] == 0) continue;
		ret = min(ret, dist[finish.first][finish.second][i]);
	}
	
	cout << ret - 1 << '\n';
	// ó������ ������ �ſ��� �ѹ� ��� �ϴµ�
	// ���������� ó������ �� ���°ɷ� �Ǿ��ֱ⿡ ���� ����� -1 
	
	return 0;
}
