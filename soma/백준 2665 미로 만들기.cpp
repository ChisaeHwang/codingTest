#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int arr[51][51];

int dijkstra(int n, vector<vector<int>>& board) {
	vector<vector<int>> dist(n, vector<int>(n, INF));
	
 	dist[0][0] = board[0][0] == 1 ? 0 : 1;
	
	priority_queue<pair<int, pair<int, int>>, 
               vector<pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> pq;


	pq.push({dist[0][0], {0, 0}});
	
	while(pq.size()) {
		int d = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		
		if(dist[x][y] < d) continue; // 방문 체크 
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
				// board의 다음방이 흰방이면 0 검은방이면 1 
				int cost = d + (board[nx][ny] == 1 ? 0 : 1);
				
				if(cost < dist[nx][ny]) {
					dist[nx][ny] = cost;
					pq.push({cost, {nx, ny}});
				}    
			} 	
		}
	}
	return dist[n-1][n-1];	
}

int main() {
	
	cin >> n;
	
	vector<vector<int>> board(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	cout << dijkstra(n, board) << '\n';
	
	
	
	
	return 0;
}
