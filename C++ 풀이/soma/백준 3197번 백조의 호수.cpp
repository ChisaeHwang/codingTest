#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char arr[1501][1501];
int visited[1501][1501];
pair<int, int> swan;
queue<pair<int, int>> sq, wq, nSQ, nWQ;
int n, m, s_x1, s_y1;
int flag = 0;

void swanBFS() {
	while(sq.size()) {
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(visited[nx][ny]) continue;
				visited[nx][ny] = 1;
				if(arr[nx][ny] == 'X') {
					nSQ.push({nx, ny});
				} else if (arr[nx][ny] == 'L') {
					flag = 1;
					break;
				} else if (arr[nx][ny] == '.'){
					sq.push({nx, ny});
				}
			}
		}
	}
}

void waterBFS() {
	while(wq.size()) {
		int x = wq.front().first;
		int y = wq.front().second;
		wq.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(arr[nx][ny] == 'X'){
					arr[nx][ny] = '.';
					nWQ.push({nx, ny});
				}
			}
		}
	}
}

int meetSolve() {
	
	sq.push({s_x1, s_y1});
	visited[s_x1][s_y1] = 1;
	int cnt = 0;
	
	while(1) {
		swanBFS();
		if(flag) break;
		waterBFS();
		sq = nSQ;
		wq = nWQ;
		while(nSQ.size()) nSQ.pop();
		while(nWQ.size()) nWQ.pop();
		cnt++;
	}
	
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] != 'X') wq.push({i, j});
			if(arr[i][j] == 'L'){
				s_x1 = i;
				s_y1 = j;
			}
		}
	}
		
	
	cout << meetSolve() << '\n';

	return 0;
}
