#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
vector<int> d;


void solve() {
	
	if(v.size() == m) {
		for(int sum : v) {
			cout << sum << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= n; i++) {
		v.push_back(i);
		solve();
		v.pop_back();
	}
	
}

int main() {
	
	cin >> n >> m;
	
	d.push_back(1);
	d.push_back(1);
	for(int sum : d) {
			cout << sum << " ";
	}
	cout << '\n';
	
	
	return 0;
}
