#include <bits/stdc++.h>

using namespace std;

// 완탐할 때는 index를 기반으로 할 생각을 해야함 
// 부호와 숫자를 담는 두개의 리스트

vector<int> numArr;
vector<char> operArr;
int n, ret = -987654321;
string s;

int cal(char a, int b, int c) {
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}

void go(int here, int n) {
	if (here == numArr.size() - 1) {
		ret = max(ret, n);
		return;
	}
	
	// 0 1 부터 
	go(here + 1, cal(operArr[here], n, numArr[here + 1]));
	if (here + 2 <= numArr.size() - 1) { // 마지막엔 안씀 
		int temp = cal(operArr[here + 1], numArr[here + 1], numArr[here + 2]);
		go(here + 2, cal(operArr[here], n, temp));
	}
	
	return;
}


int main() {
	
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0) { // num은 0 2 4 6 짝수에 위치해있다 
			numArr.push_back(s[i] - '0');
		} else {
			operArr.push_back(s[i]);
		}
	}
	
	go(0, numArr[0]);
	
	cout << ret << '\n';
	
	
	
	
	return 0; 
}
