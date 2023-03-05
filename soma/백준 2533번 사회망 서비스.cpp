#include <bits/stdc++.h>

using namespace std;

int MAX = 1000000;
int n, a, b;
vector<int> v[MAX];

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	
	return 0;
}
