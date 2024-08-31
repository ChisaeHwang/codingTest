#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M, K; // ���� ���� N, ���� ���� M, ���Ĺ� �������� ���� K
int r,c; // ��ǥ (r,c)
int trash_size=0, max_size=0; // ���Ĺ� ũ��
bool map[102][102];
bool visited[102][102];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(int y, int x){
    trash_size++;
    visited[y][x] = true;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;

        if (map[ny][nx] == true && visited[ny][nx] == false)
        {
            DFS(ny, nx);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0;i<K;i++){
        cin >> r >> c;
        map[r][c] = true;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if (map[i][j] == true && visited[i][j] == false)
            {
                trash_size = 0; // ������ �ش� dfs�� ������ trash_size�� ���µ� 
                DFS(i, j); // ���� trash_size�� ���������� �ƴϸ� �Լ��ȿ� �Է��ϵ��� ������ ¥���� 
                max_size = max(max_size, trash_size);
            }
        }
    }

    cout << max_size << "\n";

    return 0;
}
