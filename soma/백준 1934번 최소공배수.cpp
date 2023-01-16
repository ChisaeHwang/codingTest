#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int gcb(int a, int b) {
	while(b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	
	return a;
}

int main() {
	
	cin >> t;
	
	while(t--) {
		cin >> n >> m;
		
		cout << (n * m) / gcb(n, m)  << '\n';
		
	}
	
	return 0;
} 
