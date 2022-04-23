#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	stack<int>s;
	int t;
	cin >> t;
	int result = 0;
	int n;
	
	while(t--){
		cin >> n;
		if (n == 0){ // 0이 나오면 스택 뺴기 
			s.pop();
		} else {
			s.push(n); // 스택 더하기 
		}
	}
	
	while(!s.empty()){ // 스택에 있는 모든값 더하기 
		result += s.top();
		s.pop();
	}
	
	cout << result;
	
	return 0;
    
}




