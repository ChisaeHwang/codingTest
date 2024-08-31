#include <iostream>

using namespace std;

char a[55][55];
bool check[55][55];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// (px, py) -> (x, y) 
bool go(int x, int y, int px, int py, char color){
	 if(check[x][y]) {
	 	return true;	
	 }
	 check[x][y] = true;
	 for(int k=0; k<4; k++){
	 	int nx = x+dx[k]; // (x,y)랑 인접한 4칸 
	 	int ny = y+dy[k]; // (nx, ny)로 이동 
	 	if(0 <= nx && nx < n && 0 <= ny && ny < m){
	 		if(!(nx == px && ny == py)){ // 방문한 적 없음
			 	if(a[nx][ny] == color){
			 	 	if(go(nx, ny, x, y, color)){
	 					return true;
				 	}
			 	} 
			 }
		 }
	 }
	
	return false;
}

int main(){
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(check[i][j]) continue; // 방문 했으면
			bool ok = go(i, j, -1, -1, a[i][j]);
			if(ok) {
				cout << "YES" << '\n';
				
				return 0;
			} 
		}
	}
	
	cout << "NO" << '\n';
	
	return 0;
}
