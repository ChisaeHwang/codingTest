#include <bits/stdc++.h>

using namespace std;

int n, a, b;
vector<pair<int, int>> v;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	// sort�� �⺻������ ���������� 
	
	for (auto p : v) {
		cout << p.first << " " << p.second << '\n';
	}
	
	
	return 0;
} 
