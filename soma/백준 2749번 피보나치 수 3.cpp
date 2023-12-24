#include <bits/stdc++.h>

using namespace std;

int fibo[1500000];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long int n;
	
	cin >> n;
	
	fibo[0] = 0;
    fibo[1] = 1;
 
    for (int i = 2; i < 1500000; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;
 
    cout << fibo[n % 1500000] << '\n';

	return 0;
} 
