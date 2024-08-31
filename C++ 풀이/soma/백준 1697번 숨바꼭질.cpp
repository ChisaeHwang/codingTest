#include <bits/stdc++.h>

using namespace std;

#define max aa

int ret, n, k;
const int max = 200000;
int visited[max + 1];
int check[max + 1];

int main() {
	
	cin >> n >> k;
	
	check[n] = 1;
	visited[n] = 0;
	queue<int> q;
	q.push(n);
	
	while(q.size()) {
		int now = q.front();
		q.pop();
		
			if (now - 1 >= 0) {
				if (check[now - 1] == false) {
				visited[now - 1] = visited[now] + 1;
				check[now - 1] = 1;
				q.push(now - 1);
			}
		}
		
			if (now + 1 < max) {
				if (check[now + 1] == false) {
				visited[now + 1] = visited[now] + 1;
				check[now + 1] = 1;
				q.push(now + 1);
			}
		}
		
			if (now * 2 < max) {
				if (check[now * 2] == false) {
				visited[now * 2] = visited[now] + 1;
				check[now * 2] = 1;
				q.push(now * 2);
			}
		}
		
	}
	
	cout << visited[k] << '\n';
	
	
	
	
	return 0;
}
