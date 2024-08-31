#include<bits/stdc++.h>

using namespace std;

int n, result;
int t[30];
int p[30];

void go(int cnt, int ret) {
	
	if (cnt == n) {
		result = max(result, ret);
		return;
	}
	
	if (cnt > n) return;
	go(cnt + t[cnt], ret + p[cnt]);
	go(cnt + 1, ret);
	
	return;
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	
	go(0, 0);
	
	cout << result << '\n';
	
	
	return 0;
}
