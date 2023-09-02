#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 

int dij(int n, vector<vector<int>> &board) {
	vector<vector<int>> dist(n, vector<int>(n, INF));
	
	priority_queue<pair<int, pair<int, int>>,
					vector<pair<int, pair<int, int>>>,
					greater<pair<int, pair<int, int>>>> pq;
	
	if(board[0][0] == 0) {
		dist[0][0] = 1;
	} else {
		dist[0][0] = 0;
	}
	
	pq.push({dist[0][0], {0, 0}});
	
	while(pq.size()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		
		if(dist[x][y] < cost) continue; // 방문 체크 
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			
			int next;
			
			if(board[nx][ny] == 0) {
				next = cost + 1;
			} else {
				next = cost;
			}
			
					if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
				dist[nx][ny] = next;
				pq.push({next, {nx, ny}});
			}
		}
		
		
	}
	
	
	return dist[n - 1][n - 1];
}


int main() {
	
	int n;
	
	cin >> n;
	
	vector<vector<int>> board(n, vector<int>(n, INF));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	int ret = dij(n, board);
	
	cout << ret << '\n';
	
	return 0;
}
