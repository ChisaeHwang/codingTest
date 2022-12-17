#include <bits/stdc++.h>

using namespace std;

int arr[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};   
int n,m,cnt,cnt2;
vector <pair<int,int>>v;

void bfs(int y, int x) {
	visited[y][x] = 1;
	
	if (arr[y][x] == 1) {
		v.push_back({y, x});
		return;
	}
	
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		bfs(ny, nx);
	}
	
	return;
}



int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true) {
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		bfs(0, 0);
		
		for (pair<int, int> p : v) {
			cnt2++;
			arr[p.first][p.second] = 0;
		}
		
		bool flag = 0;
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (arr[i][j] != 0) flag = 1; // 치즈가 있으면 true 
			}
		}
		
		cnt++;
		if (!flag) {
			break;
		}
	}
	
	cout << cnt << '\n' << cnt2 << '\n';
	
	return 0;
}
