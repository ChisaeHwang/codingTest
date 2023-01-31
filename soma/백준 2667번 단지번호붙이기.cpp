#include <bits/stdc++.h>

using namespace std;

int visited[26][26];
int arr[26][26];
int sum[26][26];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, ret; 
string s;

void bfs(int y, int x, int cnt) {
	
	queue<pair<int, int>> q;
	q.push({y, x}); // x y를 queue에 넣어줌 
    visited[y][x] = cnt; // 방문 체크 
    
    while(q.size()) {
    	
	}
    
    
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j, cnt++);
			}
		}
	}
	
	return 0;
} 
