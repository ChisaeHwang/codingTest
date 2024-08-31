#include <bits/stdc++.h>

using namespace std;

#define y1 aa

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, k;
int x1, x2, y1, y2;
vector<int> ret;
int arr[101][101];
int visited[101][101];


int dfs(int y, int x) { // 이번 문제의 경우 int형 dfs로 풀어야함 
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (arr[ny][nx] != 1 && visited[ny][nx] == 0) {
			ret += dfs(ny, nx);
		}
	}
	
	return ret;
	
}

int main() {
	
	cin >> m >> n >> k; // m은 세로 n은 가로
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++){
				arr[y][x] = 1;
			}
		}
	} 
	
	for (int i = 0; i < m; i++) { // 세로 
		for (int j = 0; j < n; j++) { // 가로 
			if (visited[i][j] == 0 && arr[i][j] != 1) {
				ret.push_back(dfs(i, j));
			}
		}
	}
	
	
	
	sort(ret.begin(), ret.end());
	cout << ret.size() << '\n';
	for (int a : ret) {
		cout << a << " ";
	}
	
	return 0;
	
}
