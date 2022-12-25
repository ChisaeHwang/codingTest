 #include <bits/stdc++.h>
 
 using namespace std;
 
 int visited[61][61][61];
 int n, arr[3];
 
 int atk[6][3] = { // 경우의 수는 6가지 있다 3 x 2 (조합) 
 	{9, 3, 1},
 	{9, 1, 3},
 	{3, 1, 9},
 	{3, 9, 1},
 	{1, 3, 9},
 	{1, 9, 3}
 };
 
 
 struct SCV { // tuple 대신 struct 사용 
 	int a, b, c;
 };
 
 
 int bfs(int a, int b, int c) {
 	queue<SCV> q;
 	visited[a][b][c] = 1; // 나중에 빼주어야 하는 값이다 
 	q.push({a, b, c});
 	
 	while(q.size()) {
 	    int a = q.front().a; 
        int b = q.front().b; 
        int c = q.front().c; 
        q.pop();
        if(visited[0][0][0]) break; 
        for(int i = 0; i < 6; i++){
            int na = max(0, a - atk[i][0]);
            int nb = max(0, b - atk[i][1]); 
            int nc = max(0, c - atk[i][2]); 
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;  
            q.push({na, nb, nc}); 
        }
	}
	
	return visited[0][0][0] - 1;
 }
  
 
 int main() {
 	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << bfs(arr[0], arr[1], arr[2]) << '\n';


	
	return 0;

 }
