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
	
		for (int i=0; i<n; i++){
			while (!s.empty() && a[s.top()] < a[i]){
				// 스택이 비지 않고
				// 맨위 인덱스 보다  a[i] 가 클 경우에
				// 스택이 비거나 큰 수가 나올 때 까지 반복 
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
