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

int main() { 
	
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		int arr[n];
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		
		long long result = 0;
		
		for(int i=0; i<n; i++){ // 각 최대 공약수를 한 번씩 순회하며 더해줌 
			for(int j=i+1; j<n; j++){
				result += gcd(arr[i], arr[j]);	
			}
		}
	
	cout << result << '\n';
	
	}
	
	return 0; 
}

