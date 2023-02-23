#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int Nmap[301][301];
int visited[301][301];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m, cnt;
queue<pair<int, int>> q;

// üũ�ϸ鼭 �ϴ� ������ ���ϱ�
// ������ �ΰ��� ������������ üũ 

void bfs(int x, int y) {
	q.push({x, y});
	visited[x][y] = 1;
	
	while(q.size()) {
		int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (visited[nx][ny] == 0 && arr[nx][ny] != 0)
                {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
		
	}
}

int melt(int x, int y) {
	int cnt = 0;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (arr[nx][ny] == 0) cnt++;
	}
	
	return cnt;
}

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	int ret = 0;
	
	while(true) {
		
		int Land_cnt = 0;
		
		memset(visited, 0, sizeof(visited));
		memset(Nmap, 0, sizeof(Nmap));
			
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && visited[i][j] == 0) {
					Land_cnt++;
					bfs(i, j);	
				}
			}
		}
		
		// �� ������ �� ��� �̻����� �и��Ǵ� ������ �ð�(��)�� ���ϴ� ���α׷�
		if (Land_cnt >= 2) {
			cout << ret << '\n';
			break;
		}
		
		if (Land_cnt == 0) {
			cout << 0 << '\n';
			break;
		}
		
		// melt ���� 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					Nmap[i][j] = arr[i][j] - melt(i, j); // melt count
					if (Nmap[i][j] <= 0) Nmap[i][j] = 0; // ���� �÷ο� 	
				}
			}
		}
		
		// ���� �� �ٽ� map�� �־��ֱ� 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = Nmap[i][j];
			}
		}	
		
		ret++; // Ƚ�� ī�� 
	}
	
	
	return 0; 
}
