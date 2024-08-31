#include <bits/stdc++.h>

using namespace std;

int n, m, a;
queue<int> q;

int main() {
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	cout << "<";
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			q.push(q.front()); // 3°³¾¿´ç±è 
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	
	cout << q.front() << ">";
	
	
	return 0;
} 
