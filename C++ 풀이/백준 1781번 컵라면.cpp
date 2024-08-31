#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end()); // 데드라인순 정렬
	
	for (int i = 0; i < v.size(); i++) {
		ret += v[i].second; // 데드라인순 컵라면 수 넣기
		pq.push(v[i].second);
		if (pq.size() >= v[i].first + 1) { // 데드라인 수보다 더 많으면 
			ret -= pq.top(); // 오름차순 정렬이라 작은게 사라짐 greater<int> 빼면 내림차순 
			pq.pop();
		} 
	} 
	
	cout << ret << '\n';
	
	return 0;
}
