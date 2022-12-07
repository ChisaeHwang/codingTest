#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

string s;
int main() {
	
	// getline은 개행문자까지 받음 -> 즉 띄어쓰기 있으면 stirng 한번에 못 받음 
	getline(cin, s);

	for (int i = 0; i < s.size(); i++){ 
		if (s[i] >= 65 && s[i] < 97) { // 대문자인 경우 
			if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26;
			else s[i] = s[i] + 13;
		} else if (s[i] >= 97 && s[i] <= 122) { // 소문자인 경우 
			if (s[i] + 13 > 122) {
				s[i] = s[i] + 13 - 26;
			} else {
				s[i] = s[i] + 13;
			}
		}
		cout << s[i];
	}

	return 0;	
}
