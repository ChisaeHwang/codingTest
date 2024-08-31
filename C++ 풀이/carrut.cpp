#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101];
int n, m;
int x, y, sx, sy, ex, ey;

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()) {
        tie(y, x) = q.front(); // tie() 여러 값들을 넣어줄 수 있음
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny > n || nx > m || arr[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    bfs(sy, sx);

    cout << visited[ey][ex] << '\n';

}