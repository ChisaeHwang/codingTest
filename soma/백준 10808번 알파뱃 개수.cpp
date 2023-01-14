#include <bits/stdc++.h>

using namespace std;

int al[27]; 
string s;

int main() {
	

	cin >> s;
	
	for (char a : s) {
		al[a - 97]++;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << al[i] << " ";
	}
	
	return 0;
} 
