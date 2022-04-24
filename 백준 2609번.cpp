#include <iostream>
using namespace std;

int gcd(int a, int b) { // 재귀함수 사용없이 최대 공약수 구하는 '유클리드 호제법' 
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
    
    lcm = gcd(a, b); // 최대 공약수
	sum = (a * b) / lcm; // 최대 공배수 
	
	cout << sum << '\n'; 
    
    
	
	
	return 0; 
}
