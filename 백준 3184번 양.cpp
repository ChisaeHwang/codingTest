#include <bits/stdc++.h>

using namespace std;

int visited[251][251];
char arr[251][251];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, totalSheep, totalWolf;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	
	int sheep = 0;
	int wolf = 0;
	
	while(q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] == '#') continue;
			visited[ny][nx] = 1;
			if (arr[ny][nx] == 'o') sheep++;
			if (arr[ny][nx] == 'v') wolf++;
			q.push({ny, nx});
		}
	}
	
	if (sheep > wolf) totalSheep += sheep;
	else totalWolf += wolf;
	
}

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (visited[i][j]) continue;
			bfs(i, j);
		}
	}
	
	cout << totalSheep << " " << totalWolf << '\n';
	
	
	return 0;
}
