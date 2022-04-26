#include <iostream>
#include <algorithm>

int gcd(int a, int b) { // ����Լ� ������ �ִ� ����� ���ϴ� '��Ŭ���� ȣ����' 
	while(b != 0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

using namespace std;

int  A[1000000];

int main() { 
	
	int n, s, x, result; // ������ ���� ��, ������ ��ġ, �����̶� �� ���� ����� ��ġ, ������ ��ġ �ִ����� 
	
	cin >> n >> s;
	
	for(int i=0; i<n; i++){
		cin >> x;
		x = abs(s - x); //abs �Լ��� ���� ���밪���� ���� 
		A[i] = x; // s - x �� ����  
	}
	
	result = A[0];
	
	for(int i=1; i<n; i++){
		result = gcd(result, A[i]);
	}
	
	
	cout << result << '\n';
	
	return 0; 
}

