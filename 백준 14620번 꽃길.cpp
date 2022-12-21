#include <bits/stdc++.h> 

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int visited[11][11];
int arr[11][11];
int n, ret = 987654321;

int setFlower(int y, int x) {
	visited[y][x] = 1;
	int sum = arr[y][x];
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i]; 
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || !visited[ny][nx]) {
			visited[ny][nx] = 1;
			sum += arr[ny][nx];
		}
	}
	
	return sum;
} 

void removeFlower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i]; 
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
			visited[ny][nx] = 0;
		}
	}
	
	return;
} 

bool check(int y, int x) {
	if (visited[y][x]) return false; // ���ڸ� ������ false 
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i]; // 4�������ε� ������ false 
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
			return false;
		}
	}
	
	return true;
}

void flower(int cnt, int sum) { // ���� ���� ��, ������� ��

	if (cnt == 3) {
		ret = min(ret, sum);
		return;
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (check(i, j)) {
				flower(cnt + 1, sum + setFlower(i, j));
				removeFlower(i, j);
			} 
		}
	}
	
	return;
}
 

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	flower(0, 0);
	
	cout << ret << '\n';
	
	
	
	return 0;
} 
