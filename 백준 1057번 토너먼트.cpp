#include <bits/stdc++.h>

using namespace std;

int n, a, b, cnt;

int main() {
	
	cin >> n >> a >> b;
	
	while (a != b) {
		a = a - a / 2;
		b = b - b / 2;
		
		cnt++;
	}
	
	cout << cnt << '\n';
	
	
	
	return 0;
}
