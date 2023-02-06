#include <bits/stdc++.h>

using namespace std;

int n, sum;
vector<int> v;

int main() {
	
	string s;
	
	cin >> s;

    sort(s.begin(), s.end(), greater<int>());

	if (s[s.length() - 1] != '0') {
		cout << -1;
	} else {
		long long sum = 0;
		
		for (auto a : s) {
			sum += a - '0';
		}
		
		if (sum % 3 == 0) {
			cout << s;
		} else {
			cout << -1;
		}
		
		
	}
	
	
	return 0;
}   
