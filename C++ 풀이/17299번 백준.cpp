#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int over[1000001];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int>a(n); // 입력값
	vector<int>num(n); // 출력 
   
   for (int i=0; i<n; i++){
   		cin >> a[i];
   		over[a[i]] += 1;
   		cout << over[a[i]];
   }

	stack<int> s;
	s.push(0);
	
	for (int i=1; i<n; i++){
		if(s.empty()){
			s.push(i);
		}
		while (!s.empty() && over[a[s.top()]] < over[a[i]]){
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
