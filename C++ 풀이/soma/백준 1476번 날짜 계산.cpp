#include <bits/stdc++.h>

using namespace std;

int E, S, M;
int ret;

int main() {
	
	cin >> E >> S >> M;
 
 	int e = 1, s = 1, m = 1;
 	int cnt = 1;
 
	while(true) {
		
		if (e == E && s == S && m == M) {
			cout << cnt << '\n';
			break;
		} else {
			cnt++;
		}
		
		
		e += 1;
		s += 1;
		m += 1;
		 
		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
		
	}
	
	return 0;
}
