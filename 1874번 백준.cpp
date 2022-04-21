#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){
	
	stack<int> s;
	string str;
	
	int n;
	cin >> n;
	
	int m = 0;
	
	while(n--){
		int x;
		cin >> x;
		if (x > m){
			while (x > m){
				s.push(++m);
				str += '+';
			}
			s.pop();
			str += '-';
		} else {
			bool f = false;
			if(!s.empty()){
				int top = s.top();
				s.pop();
				str += '-';
				
				if(x == top){
					f = true;
				}		
			}
			if(!f){
				cout << "No" << '\n';
				return 0;	
			}
		}
	}
	
	for (auto x : str){
		cout << x << '\n';
	}
    return 0;    
}
