#include <bits/stdc++.h>

using namespace std;

int n, a, b;
vector<pair<int, int>> v;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({b, a});
	}
	
	sort(v.begin(), v.end());
	// sort�� �⺻������ ���������� 
	
	for (auto p : v) {
		cout << p.second << " " << p.first << '\n';
	}
	
	
	return 0;
} 
