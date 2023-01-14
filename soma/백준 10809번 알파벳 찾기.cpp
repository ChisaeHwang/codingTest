#include <bits/stdc++.h>

using namespace std;

int al[27]; 
string s;

int main() {
	

	cin >> s;
	
	for (int i = 0; i < 26; i++) {
		al[i] = -1;
	}
	
	for (int i = 0; i < s.size(); i++) {
		if(al[s[i] - 97] == -1) {
			al[s[i] - 97] = i;	
		}
	}
	
	for (int i = 0; i < 26; i++) {
		cout << al[i] << " ";
	}
	
	return 0;
} 
