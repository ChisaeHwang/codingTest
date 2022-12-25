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
	
	while(q.size()) { // �׳� n���� ���� m�� �� �� �ִ� ��簪 �� ã���� 
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
//	} �̷������ε� ���� �����ϴ� 
	
	// prev�� ��� ������ ������ ������ġ -> �� ��ġ -> prev[i]�� ���� 
	// �������� n�� ���� false Ż�� 
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
