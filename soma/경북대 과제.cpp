#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {

	// 기저 사례
	if(n == 1){
		return n;
	}	
	
	int ret = n * factorial(n - 1);

	return ret;
}

int main() {
	
	int num;
	cout << "숫자 입력 : ";
	cin >> num;
	
	cout << "입력된 숫자 " << num << "의 팩토리얼 : " << factorial(num) << '\n';
	
	
}
