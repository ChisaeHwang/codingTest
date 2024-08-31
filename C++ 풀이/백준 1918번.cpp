#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    stack<char> s;
    cin >> str;
    
    for(int i=0; i<str.length(); i++){
    	if(str[i] >= 'A' && str[i] <= 'Z'){
    		cout << str[i]; // 문자들은 먼저 출력 
		}
		else{
			if(str[i] == '('){ // 우선순위순으로 if문 
				s.push(str[i]);
			} else if (str[i] == '*' || str[i] == '/'){
				while (!s.empty() && (s.top() == '*' || s.top() == '/')){
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			} else if (str[i] == '+' || str[i] == '-'){
				while(!s.empty() && s.top() != '('){
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			} else if (str[i] == ')'){
				while(!s.empty() && s.top() != '('){ 	// '(' 가 나올 때 까지 다 pop 시킴 
					cout << s.top();
					s.pop();
				}
				// '(' 을 pop 
				s.pop();
			}
		}
	}
	
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	
	
	return 0;
    
}


