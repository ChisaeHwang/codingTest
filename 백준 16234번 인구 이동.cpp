#include <bits/stdc++.h>

using namespace std;

int n, sum, ret, l, r, visited[51][51], arr[51][51];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v) {
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
		if (abs(arr[ny][nx] - arr[y][x]) >= l && abs(arr[ny][nx] - arr[y][x]) <= r ) {
			visited[ny][nx] = 1;
			v.push_back({ny, nx});
			sum += arr[ny][nx];
			dfs(ny, nx, v);
		}
	}
	
}

int main() {
	
	cin >> n >> l >> r;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({i, j});
					sum = arr[i][j];
					dfs(i, j, v);
					if (v.size() == 1) continue; // 하나만 열리면 통과 
					for (pair<int, int> p : v) {
						arr[p.first][p.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}
		
		if (!flag) break;
		ret++;
	}
	
	cout << ret << '\n';
	
	return 0;
}
