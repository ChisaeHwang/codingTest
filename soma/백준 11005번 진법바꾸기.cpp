#include <bits/stdc++.h>

using namespace std;

int n, m, a;
vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	cout << v[m - 1] << '\n';
	
	
	
	
	
	return 0;
}
