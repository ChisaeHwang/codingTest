#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie();

	stack<char> ls, rs;
	
	string str;
	cin >> str;
	
	for(int i=0; i<str.length(); i++){
		ls.push(str.at(i));
	}
	
	int t; 
	cin >> t;
	
	while(t--){
		string edit;
		cin >> edit;
		if(edit == "L" && !ls.empty()){
			rs.push(ls.top());
			ls.pop();
		} else if (edit == "D" && !rs.empty()){
			ls.push(rs.top());
			rs.pop();
		} else if (edit == "B" && !ls.empty()){
			ls.pop();
		} else if (edit == "P"){
			char add;
			cin >> add;
			ls.push(add);
		}
	}
	
	while(!ls.empty()){
		rs.push(ls.top());
		ls.pop();
	}
	while(!rs.empty()){
		cout << rs.top();
		rs.pop();
	}
	
    return 0;    
}
