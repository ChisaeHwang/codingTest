#include <bits/stdc++.h>

using namespace std;

int n, ret;
int dy[4] = {1, 0, -1, 0};
int dx[4]  = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101]; // 섬구분
int dist[101][101] // 섬끼리 최단거리 
queue<pair<int,int>> q;
 
// 1. 각 섬들 구하기
// 2. 각 섬에 맞춰서 다시 bfs 돌리기
// 3. 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	} 
	
	int cnt = 0; // 각 섬부터 찾기 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push({i, j});
				
				while(q.size()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
						if (arr[nx][ny] == 0) continue;
						visited[nx][ny] = cnt;
						q.push({nx, ny}); // 섬 구분 
					}
				}
				
			}
		}
	}
	
	int sum = -1; // 각 섬에서부터 간척 느낌으로 영역확장후 최솟값 넣기 
	
	for (int i = 1; i <= cnt; i++) {
		
	}
	
	
	return 0;
}
