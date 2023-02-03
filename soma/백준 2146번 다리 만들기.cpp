#include <bits/stdc++.h>

using namespace std;

int n, ret;
int dy[4] = {1, 0, -1, 0};
int dx[4]  = {0, 1, 0, -1};
int arr[101][101];
int visited[101][101]; // ������
int dist[101][101]; // ������ �ִܰŸ� 
 
// 1. �� ���� ���ϱ�

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	} 
	
	cout << '\n';	cout << '\n';
	
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
	
	for (int l = 1; l <= cnt; l++) {
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = -1;
				if (visited[i][j] == l) {
					q.push({i, j});
					dist[i][j] = 0;
				}
			}
		}
		
		while (q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || nx >= n) continue;
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});	
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && visited[i][j] != l) { // �ٸ������̴� 
					if (sum == -1 || dist[i][j] - 1 < sum) {
						sum = dist[i][j] - 1;
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << dist[i][j] << " ";
			}
			cout << '\n';
		}
		
			cout << '\n';	cout << '\n';
	}
	
	
	cout << sum << '\n';
	
	
	return 0;
}
