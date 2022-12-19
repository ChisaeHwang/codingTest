#include <bits/stdc++.h>

using namespace std;


int a[1000001], ret[1000001];
stack<int> stk; 
int n;

int main() {
	
	cin >> n;
	
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while(stk.size() && a[stk.top()] < a[i]) { // 입력된 값이 오른쪽보다 크고, stack이 있으면 
			ret[stk.top()] = a[i]; // 오른쪽으로 큰수를 넣기 
			stk.pop();
		}
		// stack 없으면 그냥 push, 오큰수 아니면 그냥 푸쉬 
		stk.push(i); 
	}
	
	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
	
	return 0;
}
