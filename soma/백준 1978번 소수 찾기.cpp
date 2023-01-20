#include <bits/stdc++.h>

using namespace std;

int n, a, ret;

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) { // 어차피 나눠야해서 n보다 최소한 나누기 2만큼 작아야함 
		if (n % i == 0) return 0;
	}
	
	return 1; 
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		
		if (check(a)) {
			ret++;
		}
	}
	
	cout << ret << '\n';
	
	
	return 0;
}
