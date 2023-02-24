#incldue<bits/stdc++.h>
	
using namespace std;
	
int arr[1001][1001];
int visited[1001][1001][2]; // 뚫을 수 있는지 없는지 판단 여부 
int n, m, cnt;
	
void bfs(int x, int y) {



}
	
int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}	
	
	
	
	return 0;
}	
