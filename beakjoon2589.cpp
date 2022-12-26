#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char arr[54][54];
int n, m, visited[54][54], maxNum;

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if (arr[ny][nx] != 'L') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            maxNum = max(maxNum, visited[ny][nx]);
        }
    }

    return;
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
            if(arr[i][j] != 'W') {
                bfs(i, j);
            }
        }
    }

    cout << maxNum - 1<< '\n';
    // 본인값은 제외해야하기 때문에

    return 0;

}