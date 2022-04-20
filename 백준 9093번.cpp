#include <iostream>
#include <stack>
#include <string>

int s; // stackÀÇ size
int a[10001];
void push(int x) {
	a[s] = x;
	s++;
}
int pop() {
	if (s == 0) return -1;
	int t = a[s - 1];
	s--;
	return t;
}
int size() {
	return s;
}
int top() {
	if (s == 0) return -1;
	return a[s - 1];
}
int empty() {
	if (s == 0) return 1;
	else return 0;
}

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
        stack<char> s;
        for (char ch : str) {
            if (ch == ' ' || ch == '\n'){
                while (!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            } else {
            	s.push(ch);
			}
        }
    }

	return 0; 
}
