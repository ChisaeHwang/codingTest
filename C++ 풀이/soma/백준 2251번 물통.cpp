#include <bits/stdc++.h>

using namespace std;

const int MAX = 200 + 1;

int A, B, C;
int visited[MAX][MAX][MAX];

vector<int> BFS () {
	
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 0}, C});
	vector<int> result;
	
	while(q.size()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();
		
		if (visited[a][b][c]) continue;
		
		visited[a][b][c] = 1;
		
		if (a == 0) result.push_back(c);
		
		if (a + b > B) q.push({{a + b - B, B}, c});
		else q.push({{ 0, a + b}, c});
		
		if (a + b > C) q.push({{a + b - C, b}, C});
		else q.push({{ 0, b}, a + c});
		
		if (b + a > A) q.push({{A, b + a - A}, c});
		else q.push({{ b + a, 0}, c});
		
		if (b + c > C) q.push({{a, b + c - C}, C});
		else q.push({{ a, 0}, b + c});
		
		if (c + a > A) q.push({{A, b}, c + a - A});
		else q.push({{ c + a, b}, 0});
		
		if (c + b > B) q.push({{a, B}, c + b - B});
		else q.push({{a, c + b}, 0});
		
		
	}
	
	return result;
	
}

int main() {
	
	cin >> A >> B >> C;
	
	vector<int> ret = BFS();
	
	sort(ret.begin(), ret.end());
	
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << '\n';
	}
	
	
	return 0;
}
