#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int a[100][100];
int d[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
bool check[100][100];
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[0][0] = true;
    d[0][0] = 1;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (check[nx][ny] == false && a[nx][ny] == 1)
                {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    bfs(0, 0);

    printf("%d\n", d[n - 1][m - 1]);

    return 0;
}