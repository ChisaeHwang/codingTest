#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;

int visited[1000001];

int BFS() {
	
	queue<int> q;
	q.push(S);
	visited[S] = 1;
	
	while(q.size()) {
		
		int now = q.front();
		q.pop();
		
		if (now == G) {
			return visited[now] - 1;
		}
		
		int next[2] = {now + U, now - D};
		
		for (int i = 0; i < 2; i++) {
			if (next[i] <= 0 || next[i] > F || visited[next[i]]) continue;
			visited[next[i]] = visited[now] + 1;
			q.push(next[i]);
		}	
		
		
	}	
	
	return -1;
}

int main() {
	
	
	cin >> F >> S >> G >> U >> D;
	
	int ret = BFS();
	if(ret == -1) cout << "use the stairs" << '\n';
	else cout << ret << '\n';
	 
	
	return 0;
}
