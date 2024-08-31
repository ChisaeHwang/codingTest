#include <cstdio>
#include <queue>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    int n, m; // 가로(열) 세로(행)
    scanf("%d %d", &m, &n);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            d[i][j] = -1; // 아직 방문안한 토마토
            if (a[i][j] == 1)
            {
                q.push(make_pair(i, j)); // 익은 토마토 큐 넣기
                d[i][j] = 0;             // 원래 익은 토마토
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (a[nx][ny] == 0 && d[nx][ny] == -1)
                {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans < d[i][j])
            {
                ans = d[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0 && d[i][j] == -1)
            { // 안악고 방문안한 토마토
                ans = -1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}