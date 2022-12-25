#include <bits/stdc++.h>

using namespace std;
#define prev aaa

const int MAX = 200000;
int visited[MAX + 1];
int cnt[MAX + 1];
int prev[MAX + 1];
int n, m;

int main() {
	
	cin >> n >> m;
	
	visited[n] = 1;
	vector<int> v;
	queue<int> q;
	q.push(n);
	
	while(q.size()) { // 그냥 n값에 따른 m에 갈 수 있는 모든값 다 찾아줌 
		int now = q.front();
		q.pop();
		
		if (now == m) {
			break;
		}
		
		for (int next : {now+1, now-1, now*2}) {
			if (0 <= next && next <= MAX) {
				if(!visited[next]) {
					q.push(next);
					visited[next] += visited[now] + 1;
					prev[next] = now;
				}
			}
		}	
	}
	
//	pair<int, int> d[] = {{1, 1}, {1, -1}, {2, 0}};
//	for (int i = 0; i < 3; i++){
//		int nx = here * d[i].first + d[i].second;
//	} 이런식으로도 구현 가능하다 
	
	// prev로 경로 추적이 가능함 동생위치 -> 내 위치 -> prev[i]로 추적 
	// 마지막에 n이 들어가면 false 탈출 
	for (int i = m; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);
	
	cout << visited[m] - 1 << '\n';

	reverse(v.begin(), v.end());

	for (int i : v) {
		cout << i << ' ';
	}
	
	return 0;
}
