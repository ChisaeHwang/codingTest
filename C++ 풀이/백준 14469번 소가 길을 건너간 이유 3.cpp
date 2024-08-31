#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		ret = max(ret, v[i].first);
		ret += v[i].second;
	}
	
	cout << ret << '\n';
	
	return 0;
}
