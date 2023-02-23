#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int Nmap[301][301];
int visited[301][301];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m, cnt;
queue<pair<int, int>> q;

// 체크하면서 일단 최저값 구하기
// 빙산이 두개로 나뉘어지는지 체크 

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
		
		// 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램
		if (Land_cnt >= 2) {
			cout << ret << '\n';
			break;
		}
		
		if (Land_cnt == 0) {
			cout << 0 << '\n';
			break;
		}
		
		// melt 로직 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					Nmap[i][j] = arr[i][j] - melt(i, j); // melt count
					if (Nmap[i][j] <= 0) Nmap[i][j] = 0; // 오버 플로우 	
				}
			}
		}
		
		// 녹은 값 다시 map에 넣어주기 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = Nmap[i][j];
			}
		}	
		
		ret++; // 횟수 카운 
	}
	
	
	return 0; 
}
