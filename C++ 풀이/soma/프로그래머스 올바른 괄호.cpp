#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string s;
	queue<int> q;
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }
    
    int cnt = 0;
    
    while(q.size()) {
    	char a = q.front();
    	q.pop();
    	if (a == '('){
    		cnt++;
		} else if (a == ')'){
			cnt--;
		}
		
		if (cnt < 0) break;
	}
    
    if (cnt == 0) cout << "true" << '\n';
    else cout << "false" << '\n';
    
	return 0;
} 
