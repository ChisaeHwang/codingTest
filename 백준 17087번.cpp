#include <iostream>
#include <algorithm>

int gcd(int a, int b) { // 재귀함수 사용없이 최대 공약수 구하는 '유클리드 호제법' 
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
	
	int n, s, x, result; // 수빈의 동생 수, 수빈이 위치, 수빈이랑 각 동생 상대적 위치, 동생들 위치 최대공약수 
	
	cin >> n >> s;
	
	for(int i=0; i<n; i++){
		cin >> x;
		x = abs(s - x); //abs 함수를 통해 절대값으로 설정 
		A[i] = x; // s - x 를 통해  
	}
	
	result = A[0];
	
	for(int i=1; i<n; i++){
		result = gcd(result, A[i]);
	}
	
	
	cout << result << '\n';
	
	return 0; 
}

