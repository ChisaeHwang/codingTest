#include <bits/stdc++.h>

using namespace std;

int n, ret;
int dy[4] = {1, 0, -1, 0};
int dx[4]  = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101]; // ������
int dist[101][101] // ������ �ִܰŸ� 
queue<pair<int,int>> q;
 
// 1. �� ���� ���ϱ�
// 2. �� ���� ���缭 �ٽ� bfs ������
// 3. 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	} 
	
	int cnt = 0; // �� ������ ã�� 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push({i, j});
				
				while(q.size()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
						if (arr[nx][ny] == 0) continue;
						visited[nx][ny] = cnt;
						q.push({nx, ny}); // �� ���� 
					}
				}
				
			}
		}
	}
	
	int sum = -1; // �� ���������� ��ô �������� ����Ȯ���� �ּڰ� �ֱ� 
	
	for (int i = 1; i <= cnt; i++) {
		
	}
	
	
	return 0;
}
