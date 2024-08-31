#include <iostream>
#include <algorithm>

using namespace std;


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

