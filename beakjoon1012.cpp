#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, k, x, y, ret, ny, nx;
int a[51][51];
bool visited[51][51];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--) {

        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> m >> n >> k; // 가로, 세로
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;  // 좌표를 받는다
            a[y][x] = 1; // y는 행 x는 열
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}

void fun() {

    int a = 0;

    cin >> a;

    switch (expression)
    {
    case 
        /* code */
        break;
    
    default:
        break;
    }
}