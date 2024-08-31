#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int main() {
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			cnt++;
		} 
		
		if (i % 25 == 0) {
			cnt++;
		}
		
		if (i % 125 == 0) {
			cnt++;
		}
	}

	cout << cnt << '\n';
	
	return 0; 
}
