#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int a[30][30];
int group[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;
int ans[25*25];

void bfs(int x, int y, int cnt) {
	
    queue<pair<int,int>> q;
    q.push(make_pair(x,y)); // x y를 queue에 넣어줌 
    group[x][y] = cnt; // 방문 체크 
    
    while (!q.empty()) {
        x = q.front().first; // 행 
        y = q.front().second; // 열 
        q.pop(); // 둘다 빼줌 
        for (int k=0; k<4; k++) {
            int nx = x+dx[k]; // 인접한 4 방향 다 처리 
            int ny = y+dy[k]; // 인접한 4 방향 다 처리 
            if (0 <= nx && nx < n && 0 <= ny && ny < n) { // 범위안에 있을 경우 
                if (a[nx][ny] == 1 && group[nx][ny] == 0) { // 집이 있고 방문한 적이 있으면 같은 그룹 
                    q.push(make_pair(nx,ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }
}

int main() {
	
	scanf("%d",&n);
	
 	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
	
	
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j] == 1 && group[i][j] == 0){
				bfs(i, j, ++cnt);
			}
		}
	}
	
    printf("%d\n",cnt);
	
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[group[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }

	return 0;
}
