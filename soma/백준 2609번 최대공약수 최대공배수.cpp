#include <iostream>
using namespace std;

int gcd(int a, int b) { // ����Լ� ������ �ִ� ����� ���ϴ� '��Ŭ���� ȣ����' 
	while(b != 0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    
    int lcm = 0; 
    int sum = 0;
    
    lcm = gcd(a, b); // �ִ� �����
	sum = (a * b) / lcm;
	
	cout << lcm << '\n' << sum; 
    
    
	
	
	return 0; 
}
