#include <bits/stdc++.h>

using namespace std;

int n, a;
vector<int> v;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	// sort는 기본적으로 오츰차순임 
	
	for (int a : v) {
		cout << a << '\n';
	}
	
	
	return 0;
} 
