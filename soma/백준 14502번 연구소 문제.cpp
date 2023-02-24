#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[10][10];
int visited[10][10];
queue<pair<int, int>> q;
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;

void bfs(int x, int y) {
    
    q.push({x, y});
    visited[x][y] = 1;
    
    while(q.size()) {
    	int x = q.front().first;
    	int y = q.front().second;
    	q.pop();
    	
    	for (int i = 0; i < 4; i++) {
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		
    		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
    		if (arr[nx][ny] == 1 || arr[nx][ny] == 2) continue;
    		visited[nx][ny] = 1;
    		q.push({nx, ny});
		}
	}
}

int cal() {
	memset(visited, 0, sizeof(visited));
	
	for (pair<int, int> a : virus) {
		bfs(a.first, a.second);
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (arr[i][j] == 0 && !visited[i][j]) cnt++;
		}
	}
	
	return cnt;
}

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int c;
    		cin >> c;
    		arr[i][j] = c;
    		
    		if (c == 2) virus.push_back({i, j});
    		if (c == 0) wall.push_back({i, j});
		}
	}
    
    for (int i = 0; i < wall.size(); i++) {
    	for (int j = 0; j < i; j++) {
    		for (int k = 0; k < j; k++) {
    			arr[wall[i].first][wall[i].second] = 1;
    			arr[wall[j].first][wall[j].second] = 1;
    			arr[wall[k].first][wall[k].second] = 1;
    			ret = max(ret, cal());
    			arr[wall[i].first][wall[i].second] = 0;
    			arr[wall[j].first][wall[j].second] = 0;
    			arr[wall[k].first][wall[k].second] = 0;
			}
		}
	}
    
    cout << ret << '\n';
    
    
    return 0;
}
