#include <bits/stdc++.h>

using namespace std;

long long n, m;

long long gcd(long long a, long long b) {
	while(b != 0) {
		long long r = a%b;
		a = b;
		b = r;
	}
	
	return a;
}

int main() {  
	

		cin >> n >> m;
		
		long long ret = gcd(n, m);
		
		for (int i = 0; i < ret; i++) {
			cout << 1;
		}
		
		cout << '\n';
	
	return 0;
} 
