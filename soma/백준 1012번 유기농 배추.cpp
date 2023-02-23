#include <bits/stdc++.h>

using namespace std;

int t, n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[51][51];
int visited[51][51];
queue<pair<int, int>> q; 

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
    		
    		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    		if (visited[nx][ny]) continue;
    		if (arr[nx][ny] == 0) continue;
    		visited[nx][ny] = 1;
    		q.push({nx, ny});
		}
	}
}

int main() {
    
    cin >> t;
    
    while(t--) {
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        cin >> n >> m >> k;
        
        int cnt = 0;
        
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        
        for (int i = 0; i < n; i++) {
        	 for (int j = 0; j < m; j++) {
        		if (arr[i][j] == 0 || visited[i][j]) continue;
        		bfs(i, j);
        		cnt++;
			}
		}
		
		cout << cnt << '\n';
        
    }
    
    
    
    return 0;
}
