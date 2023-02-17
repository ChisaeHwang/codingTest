#include <bits/stdc++.h>

using namespace std;

int n;
int visited[15];
int ret[7];

void dfs(int s, int d) {
	
	if (d == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ret[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = s; i < n; i++) {
		ret[d] = visited[i];
		dfs(i + 1, d + 1);
	}
	
}

int main() {
	
	while(true) {
		
		cin >> n;
		
		if (n == 0) break;
		
		for (int i = 0; i < n; i++) {
			cin >> visited[i];
		}
		dfs(0, 0);
		
		cout << '\n';
	}
	
	
	
	return 0;
} 
