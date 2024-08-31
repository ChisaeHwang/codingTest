#include <bits/stdc++.h>

using namespace std;

int A, P;
int visited[300001]; 

void dfs(int num) {
	
	visited[num]++;
	
	if (visited[num] == 3) return;
	
	int next = 0;
	
	while(num) {
		next += pow(num % 10, P);
		num /= 10;
	}
	
	dfs(next);
	
}

int main() {
	
	cin >> A >> P;
	
	int cnt = 0;
	
	dfs(A);
	
	for (int i = 0; i < 300001; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}
	
	cout << cnt << '\n';
	
	
	return 0;
}
