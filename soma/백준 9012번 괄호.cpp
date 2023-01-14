#include <bits/stdc++.h>

using namespace std;

int n;
string s;

string go(string s) {
	int par = 0; // parentheses ��ȣ 
	for (int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			par += 1;
		} else {
			par -= 1;
		}
		
		if(par < 0){ // - -> ) ������ �������� ������ ������ NO 
			return "NO"; 
		}
	}
	
	if (par == 0){
		return "YES";
	} else {
		return "NO";
	}
}

int main() {
	
	cin >> n;
	
	while(n--) {
		cin >> s;
		cout << go(s) << '\n';
	}
	
	
	return 0;
}  
