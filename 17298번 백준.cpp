#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int>a(n); // 입력값
	vector<int>num(n); // 출력 
   
   for (int i=0; i<n; i++){
   		cin >> a[i];
   }

	stack<int> s;
	s.push(0);
	
	for (int i=1; i<n; i++){
		if(s.empty()){
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]){
			num[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	
	while (!s.empty()){
		num[s.top()] = -1;
		s.pop();
	}
	
	for (int c : num) {
		cout << c << " ";
	}
	
	
	return 0; 
}
