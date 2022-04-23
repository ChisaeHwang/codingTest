#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double arr[30];
    
    int n;
    cin >> n;
    
    string str;
    stack<double> s;
    cin >> str;
    
    for(int i=0; i<n; i++){
    	cin >> arr[i];
	}
    
    for(int i=0; i<str.length(); i++){
    	if(str[i] == '*'){
    		double a = s.top();
    		s.pop();
    		double b = s.top();
    		s.pop();
    		s.push(b * a);
		} else if(str[i] == '/'){
			double a = s.top();
    		s.pop();
    		double b = s.top();
    		s.pop();
    		s.push(b / a);
		} else if(str[i] == '+'){
			double a = s.top();
    		s.pop();
    		double b = s.top();
    		s.pop();
    		s.push(b + a);
		} else if(str[i] == '-'){
			double a = s.top();
    		s.pop();
    		double b = s.top();
    		s.pop();
    		s.push(b - a);
		} else {
			s.push(arr[str[i]-65]);
		}
	}
	
	cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
	
	
	return 0;
    
}


