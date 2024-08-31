#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

int n;

int main() {
	int n;
	while(cin >> n) {
		int temp = 0;
		for (int i = 1; i <= n; i++){
			temp = temp * 10 + 1;
			temp %= n;
			
			if (temp == 0) {
				cout << i << '\n';
				break;
			}
		}
	}
	 
	
	return 0;
} 
