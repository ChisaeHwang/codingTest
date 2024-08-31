#include <iostream>

using namespace std;

long long arr[101] = {0, 1, 1, };

long long go(int n){
	if(n < 3){
		return arr[n];
	}
	if(arr[n] == 0){
		arr[n] = go(n - 3) + go(n - 2);
	}
	
	return arr[n];
}

int main(){
	
	int t, n;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		cout << go(n) << '\n';
	}
	
	return 0;
}

// 피보나치 수열의 값은 N이 커짐에 따라 빠르게 증가하므로, 
// 반드시 long long 자료형을 사용해야한다
