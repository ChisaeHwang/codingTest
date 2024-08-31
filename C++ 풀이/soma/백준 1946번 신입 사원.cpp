#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<pair<int, int>> v;

int main() {
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		int cnt = 0;
		int max = 987654321;
		v.clear();
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}
		
		sort(v.begin(), v.end());
		
		for (int i = 0; i < n; i++) {
			if (max > v[i].second) {
				max = v[i].second;
				cnt++;
			}
		}
		
		cout << cnt << '\n';
	}
	
	
	return 0;
}
