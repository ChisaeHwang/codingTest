#include <iostream>
using namespace std;
int arr[501][501]= {};
int dp[501][501] = {};
bool visited[501][501] = { 0 };
int m, n;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {

	
	if (x == n  && y == m) {
		//dp[x][y] = 1;
		return 1; //�����̶�� 1�� ��ȯ�մϴ�. 
	}
	if (visited[x][y]) //�̹� �湮�� ���̶�� �ش� dp���� �������ش�.
		return dp[x][y];
		
	visited[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && nx <= n && ny > 0 && ny <= m)
			if (arr[x][y] > arr[nx][ny]) 
				dp[x][y] += dfs(nx, ny); 
		
	}
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	
	
	cout << dfs(1, 1)<< '\n';
	return 0;	
}

