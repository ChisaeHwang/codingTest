#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {

	// ���� ���
	if(n == 1){
		return n;
	}	
	
	int ret = n * factorial(n - 1);

	return ret;
}

int main() {
	
	int num;
	cout << "���� �Է� : ";
	cin >> num;
	
	cout << "�Էµ� ���� " << num << "�� ���丮�� : " << factorial(num) << '\n';
	
	
}
