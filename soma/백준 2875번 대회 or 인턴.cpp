#include <bits/stdc++.h>

using namespace std;

int n, m, k, ret; 

int main() {
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < k; i++) {
		if (n / 2 < m) {
			m -= 1;
		} else {
			n -= 1;
		}
	}
	
 	cout << min(n / 2, m) << "\n";
	
	return 0;
}
