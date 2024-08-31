#include <bits/stdc++.h>

using namespace std;

// 배열값이 너무 커서 카운팅 배열을 못함 
int n, l, a, b, ret, idx, cnt;

int main() {
	
	cin >> n >> l;
	
	vector<pair<int, int>> v(n); 
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].second <= idx) continue;
		
		if (idx < v[i].first) { // 현재 위치가 물웅덩이 start 보다 작은 경우에 (안 겹치는 경우) 
			// 모듈러 연산 -> true가 나오면 1이란 뜻 -> 즉 판자하나 더 넣어야함 
			cnt = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0); 
			idx = v[i].first + cnt * l; // 물웅덩이 start 위치 + 판자 수 * 판자 길이 
		} else { // 현재 위치가 물웅덩이 start보다 큰 경우에 (겹치는 경우) 
			cnt = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0); 
			idx += + cnt * l;
		}
		
		ret += cnt;
	}
	
	cout << ret << '\n';

	
	return 0;
} 
