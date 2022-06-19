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
            scanf("%d",&a[i][j]); // 입력받기 
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && g[i][j] == 0) { // 섬이고 그룹번호 없으면 
                g[i][j] = ++cnt; // 그룹 번호 만들어주기 
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while (!q.empty()) { // 모든점 BFS로 방문하기 
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (a[nx][ny] == 1 && g[nx][ny] == 0) {
                                g[nx][ny] = cnt; // 그룹번호 같은 값으로 만들어주기 
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -1; // l번 섬과 거리 구하기 가능 
    for (int l=1; l<=cnt; l++) {
        queue<pair<int,int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i][j] = -1; // 거리 -1로 모든 점 초기화 
                if (g[i][j] == l) { // 그룹번호 l이랑 같으면 l번 섬임 
                    q.push(make_pair(i,j)); // l번 섬에 포함된 모든칸의 번호 q에 넣기 
                    d[i][j] = 0; // 거리 0 
                }
            }
        }
        while (!q.empty()) { // 시작점 구했으르몰 BFS로 거리 구하기 
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (d[nx][ny] == -1) {
                        d[nx][ny] = d[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] == 1 && g[i][j] != l) { // 섬인데 그룹번호 l번 아니면 
                    if (ans == -1 || d[i][j]-1 < ans) { // 거기까지 거리에서 1을 뺀 최솟값 
                        ans = d[i][j]-1;
                    }
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
	return 0;
}
