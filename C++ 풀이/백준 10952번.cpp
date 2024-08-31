#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin.ignore(); // cin.ignore() 이 없을 경우 getline은 \n 까지 인식하기에 모든 스택을 인식하지 못한다
    while(t--){
        string str;
        getline(cin, str);
        str += '\n';
        stack<char> s;
        for (char ch : str) {
            if (ch == ' ' || ch == '\n'){
                while (!s.empty()){
                    cout << s.top;
                    s.pop();
                }
            }
        }
    }
    
     // lifo : last in first out, stack을 역순으로 바꿔줌

	return 0; 
}
