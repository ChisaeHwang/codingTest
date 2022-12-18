#include <bits/stdc++.h>

using namespace std;


int t;
string s;

bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(') {
			stk.push(c);
		} else {
			if (!stk.empty()) { // 스택이 있을 경우 
				stk.pop();
			} else {
				return false;
			}
		}
	}
	
	return stk.empty(); 
	// stack이 비어 있으면 true stack에 뭐가 있으면 false 반환 
}



int main() {

	cin >> t;
	
	for (int i = 0; i < t; i++){
		cin >> s;
		
		if (check(s)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		
	}	
	
	
	
	return 0; 
} 
