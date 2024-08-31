#include<bits/stdc++.h>
using namespace std; 


const int maxInt = 101;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
int n, m;
int a[maxInt][maxInt], visited[maxInt][maxInt], x, y;

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", a[i][j]);
		}
	}
	
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	
	
	return 0;
}
