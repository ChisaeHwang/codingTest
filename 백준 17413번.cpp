#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<char> &s){
	while (!s.empty()){
	    cout << s.top();
	    s.pop();
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    bool tag = false;
    getline(cin, str);
    stack<char> s; // stack을 통해 역순이 가능함 
    for (char ch : str) {
        if (ch == '<'){
        	print(s); // < 이전 단어들 역순으로 출력 
        	tag = true;
        	cout << ch; // < 출력 
		} else if (ch == '>'){
			tag = false;
			cout << ch; // > 출력 
		} else if (tag) {
			cout << ch; // <> 안에 내용 전체 다 출력 
		} else {
	        if (ch == ' '){
				print(s);
	            cout << ch; // ' ' 출력 
	        } else {
	            s.push(ch); // 스택을 쌓다가 ' '가 나오면 결국 위에서 출력함 
			}
		}
    }
    
    print(s);
	cout << '\n';
	
	return 0; 
}
