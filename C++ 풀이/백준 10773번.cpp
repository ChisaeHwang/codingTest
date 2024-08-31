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
		if (n == 0){ // 0�� ������ ���� ���� 
			s.pop();
		} else {
			s.push(n); // ���� ���ϱ� 
		}
	}
	
	while(!s.empty()){ // ���ÿ� �ִ� ��簪 ���ϱ� 
		result += s.top();
		s.pop();
	}
	
	cout << result;
	
	return 0;
    
}




