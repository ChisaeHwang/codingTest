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
            scanf("%d",&a[i][j]); // �Է¹ޱ� 
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && g[i][j] == 0) { // ���̰� �׷��ȣ ������ 
                g[i][j] = ++cnt; // �׷� ��ȣ ������ֱ� 
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while (!q.empty()) { // ����� BFS�� �湮�ϱ� 
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (a[nx][ny] == 1 && g[nx][ny] == 0) {
                                g[nx][ny] = cnt; // �׷��ȣ ���� ������ ������ֱ� 
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -1; // l�� ���� �Ÿ� ���ϱ� ���� 
    for (int l=1; l<=cnt; l++) {
        queue<pair<int,int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i][j] = -1; // �Ÿ� -1�� ��� �� �ʱ�ȭ 
                if (g[i][j] == l) { // �׷��ȣ l�̶� ������ l�� ���� 
                    q.push(make_pair(i,j)); // l�� ���� ���Ե� ���ĭ�� ��ȣ q�� �ֱ� 
                    d[i][j] = 0; // �Ÿ� 0 
                }
            }
        }
        while (!q.empty()) { // ������ ���������� BFS�� �Ÿ� ���ϱ� 
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
                if (a[i][j] == 1 && g[i][j] != l) { // ���ε� �׷��ȣ l�� �ƴϸ� 
                    if (ans == -1 || d[i][j]-1 < ans) { // �ű���� �Ÿ����� 1�� �� �ּڰ� 
                        ans = d[i][j]-1;
                    }
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
	return 0;
}
