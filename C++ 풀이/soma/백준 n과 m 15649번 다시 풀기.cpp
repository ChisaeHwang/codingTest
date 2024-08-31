#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
bool used[9];


void solve() {
	
	if(v.size() == m) {
		for(int sum : v) {
			cout << sum << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			used[i] = true;
			v.push_back(i);
			solve();
			v.pop_back();
			used[i] = false;
		}
	}
	
}

int main() {
	
	cin >> n >> m;
	
	solve();
	
	return 0;
}
