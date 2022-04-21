#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    cin.ignore();
   
    while(t--){
        string str;
        
        getline(cin, str);
        str += '\n';
        stack<char> s; // stack을 통해 역순이 가능함 
        for (char ch : str) {
            if (ch == ' ' || ch == '\n'){
                while (!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            } else {
            	s.push(ch); // 순회하면서 위에서 출력함 
			}

        }
    }

	return 0; 
}
