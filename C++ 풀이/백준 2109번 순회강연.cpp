#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({b, a}); // Day순으로 정렬하기 위해 
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) { // day안에 처리 못하면 pq.pop 
			pq.pop(); // pq는 기본적으로 오름차순 정렬이라 작은거부터 빠짐 
		}
	}
	
	while(pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret << '\n';
	
	return 0;
}
