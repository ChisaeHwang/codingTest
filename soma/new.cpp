#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
vector<int> d;


void solve(int start) {
	
	if(v.size() == m) {
		for(int sum : v) {
			cout << sum << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i = start; i <= n; i++) {
		v.push_back(i);
		solve(i);
		v.pop_back();
	}
	
}

int main() {
	
	cin >> n >> m;
	
	solve(1);
	
	return 0;
}
