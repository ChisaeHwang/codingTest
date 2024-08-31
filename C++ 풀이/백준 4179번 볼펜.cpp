#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
char arr[1001][1001];
int n, m, sx, sy, x, y, ret = 0;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int fire_check[1001][1001], person_check[1001][1001];

// 불의 최단 거리보다 병훈이가 좀 더 빨라야한다 


bool in(int a, int b) { // 오버 플라우 체크 용도 
	return 0 <= a && a < n && 0 <= b && b < m;
}


int main() {
		
	cin >> n >> m;
	fill(&fire_check[0][0], &fire_check[0][0] + 1001 * 1001, INF);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'F') {
				fire_check[i][j] = 1;
				q.push({i, j}); // 큐는 그냥 푸쉬 
			}
			else if (arr[i][j] == 'J') {
				sx = j;
				sy = i;
			}
		}
	}
	
	
	while(q.size()) {
	tie(y, x) = q.front();
	q.pop();
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (fire_check[ny][nx] != INF || arr[ny][nx] == '#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ny, nx});
		}	
	}
	
	person_check[sy][sx] = 1;
	q.push({sy, sx});
	
	while(q.size()) {
	int y = q.front().first;
	int x = q.front().second;
	q.pop();
	
	if (x == 0 || y == 0 || x == m - 1 || y == n - 1) {
		ret = person_check[y][x];
		break;
	}
	
	for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (person_check[ny][nx] || arr[ny][nx] == '#') continue;
			if (fire_check[ny][nx] <= person_check[y][x] + 1) continue; // fire가 person 보다 빠른 경우 
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ny, nx});
		}	
	}
	
 	 if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	
	return 0;
}
