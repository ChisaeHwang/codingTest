#include <bits/stdc++.h>

using namespace std;

int l, c;

bool check(string &str) {
	int ja = 0;
	int mo = 0;
	
	for (char x : str) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo++;
		} else {
			ja++;
		}
	}
	
	return ja >= 2 && mo >= 1;
}

void solve(int n, vector<char> &al, string pass, int i) {
	
	if (pass.length() == n) {
		if (check(pass)) {
			cout << pass << '\n';
		}
		return;
	}
	
	if (i >= al.size()) return;
	solve(n, al, pass + al[i], i + 1);
	solve(n, al, pass, i + 1);
	
	
}
 
int main() {
	
	cin >> l >> c;
	
	vector<char> v(c);
	
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	solve(l, v, "", 0); 
	
	
	
	return 0;
}
