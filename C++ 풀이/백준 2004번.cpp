#include <iostream>
#include <algorithm>

using namespace std; 

int main() { 
	
	long long two=0, five=0; // nCm = n! / (n-m)! * m!
	long long n, m; // n!의 개수에서 (n-m)!과 m!의 개수를 빼야함 
	
	cin >> n >> m;  // 의 개수 = 22 - 10 - 10 = 2, 5의 개수 = 6 - 2 - 2 = 2
	
	for (long long i=2; i<=n; i*=2){
		two += n/i;
	}
	for (long long i=2; i<=n-m; i*=2){
		two -= (n-m)/i;
	}
	for (long long i=2; i<=m; i*=2){
		two -= m/i;
	}
	for (long long i=5; i<=n; i*=5){
		five += n/i;
	}
	for (long long i=5; i<=n-m; i*=5){
		five -= (n-m)/i;
	}
	for (long long i=5; i<=m; i*=5){
		five -= m/i;
	}
	
	cout << min(two, five) << '\n'; //최솏값을 반환 시키는 min 함수 
	
	return 0; 

}

