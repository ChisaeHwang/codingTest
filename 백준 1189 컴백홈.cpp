#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char arr[10][10];
int visited[10][10]; 
string s;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int bfs(int y, int x) {
	
	if (y == 0 && x == m - 1) {
		if (k == visited[y][x]) return 1;
		else return 0;
	}
	int ret = 0; 
	for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
			if(arr[ny][nx] == 'T') continue;
			visited[ny][nx] = visited[y][x] + 1; // �ִܰŸ� BFS
			ret += bfs(ny, nx);
			visited[ny][nx] = 0; // visited= �ʱ�ȭ 
	}
	
	return ret;
}

int main() {
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	visited[0][0] = 1;
	
	// �̰� �迭�������� Ž���ѵ� �̰� ���򰥸��� ���� �ù� 
	
	cout << bfs(n - 1, 0) << '\n';
	
	return 0;
} 
