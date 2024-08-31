#include <bits/stdc++.h>
#define y1 aa

using namespace std;

int visited[301][301];
char arr[301][301];
int n, m, x1, y1, x2, y2;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
string s;

void bfs(int y, int x) {
	queue<int> q;
	q.push(1000 * y + x);
    visited[y][x] = 1; 
    int cnt = 0; 
    while(arr[y2][x2] != '0'){ 
        cnt++;
        queue<int> temp; 
        while(q.size()){
            int y = q.front() / 1000; 
            int x = q.front() % 1000;  
            q.pop();  
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
                visited[ny][nx] = cnt;  
                if(arr[ny][nx] != '0'){
                    arr[ny][nx] = '0'; 
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx); 
            }
        }
        q = temp;  
    }
	
}

int main() {
	
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--; 
    
    for(int i = 0; i < n; i++){
        scanf("%s", arr[i]); 
    }  
    
    bfs(y1, x1);
	
	cout << visited[y2][x2] << '\n';
	
		
	
	return 0;
}
