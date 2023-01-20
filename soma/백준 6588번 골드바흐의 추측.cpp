#include <bits/stdc++.h>

using namespace std;

int t, n;

// 시간초과 풀이 

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
	
	while(true) {
		
		cin >> n;
		
		if (n == 0 || n <= 4) break;
		
		vector<int> v;
		
		if (n % 2 != 0) cout << "Goldbach's conjecture is wrong." << '\n';
		
		for (int i = 3; i <= n; i++) {
			for (int j = n; j >= 0; j--) {
				if (check(i) && check(j) && i + j == n) {
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		
		cout << n << " = " << v[0] << " + " << v[1] << '\n';
		
	}
	
	
	return 0;
}
