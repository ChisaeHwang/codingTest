#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n;

int dijkstra(int n, vector<vector<int>>& board) {
	vector<vector<int>> dist(n, vector<int>(n, INF));

	priority_queue<pair<int, pair<int, int>>, 
               vector <pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> pq;



}

int main() {
	
	cin >> n;
	
	vector<vector<int>> board(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	cout << dijkstra(n, board) << '\n';
	
	
	
	
	return 0;
}
