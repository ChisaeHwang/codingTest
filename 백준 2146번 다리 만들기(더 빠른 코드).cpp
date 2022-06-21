#include <cstdio>
#include <queue>
using namespace std;
int a[100][100];
int g[100][100];
int d[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && g[i][j] == 0) {
                g[i][j] = ++cnt;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (a[nx][ny] == 1 && g[nx][ny] == 0) {
                                g[nx][ny] = cnt;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
    }
    
    // BFS 한 번으로 해결이 가능한 문제이다 
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j] = -1;
            if (a[i][j] == 1) { 
                q.push(make_pair(i,j)); // l번 섬이 아닌 모든 섬들을 다 q에 넣음 
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) { // BFS로 거기로부터 모든 거리 구하기 
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    g[nx][ny] = g[x][y]; // 섬을 확장하는 방식으로 다리를 만드므로
										 // 바다도 그룹번호 지정이 가능함 
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int ans = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<4; k++) { // (i, j) - (x, y)
                int x = i+dx[k]; // 인접한 i x 
                int y = j+dy[k]; // 인접한 j y
                if (0 <= x && x < n && 0 <= y && y < n) {
                    if (g[i][j] != g[x][y]) { // 그룹 번호 다를 때만 
                        if (ans == -1 || ans > d[i][j] + d[x][y]) { // 바다에 만들어지는 섬거리의 최솟값 
                            ans = d[i][j] + d[x][y];
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
