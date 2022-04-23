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
    		cout << str[i]; // ���ڵ��� ���� ��� 
		}
		else{
			if(str[i] == '('){ // �켱���������� if�� 
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
				while(!s.empty() && s.top() != '('){ 	// '(' �� ���� �� ���� �� pop ��Ŵ 
					cout << s.top();
					s.pop();
				}
				// '(' �� pop 
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


