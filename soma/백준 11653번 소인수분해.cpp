#include <bits/stdc++.h>

using namespace std;

int n, ret = 1;

int fibo(int n) {
    if (n > 1)
        return n * fact(n - 1);
    else return 1;
}

int main() {
	
	cin >> n;

	for (int i = 2; i <= n; i++) {
		ret *= i;
	}

	cout << ret << '\n';
	
	return 0; 
}
