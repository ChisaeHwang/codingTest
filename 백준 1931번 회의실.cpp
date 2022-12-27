#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret, cnt;
vector<pair<int, int>> v;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({b, a});
	} 
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= cnt) {
			cnt = max(cnt, v[i].first);
			ret++;	
		}
	}
	
	
	cout << ret << '\n';
	
	
	return 0;
}
