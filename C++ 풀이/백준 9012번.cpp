#include<iostream>
#include<string>
using namespace std;

string stack (string s) {
	int par = 0; // parentheses °ıÈ£ 
	for (int i=0; i<s.size(); i++){
		if(s[i] == '('){
			par += 1;
		} else {
			par -= 1;
		}
		
		if(par < 0){
			return "NO"; 
		}
	}
	
	if (par == 0){
		return "YES";
	} else {
		return "NO";
	}
	
}

int main(void){
	
	int a;
	cin >> a;
	
	while(a--){
		string b;
		cin >> b;
		cout << stack(b) << "\n";
		
	}
	
    return 0;    
}
