#include <bits/stdc++.h>

using namespace std;

int t, n, ret;
long long dp[101] = { 0, 1, 1, 1 };

int main() {
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		for (int i = 4; i < 101; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];	
		}
		
		cout << dp[n] << '\n';
	}

	
	
	return 0;
}


// top - bottom Ç®ÀÌ¹ý 
//
//#include <iostream>
//
//using namespace std;
//
//long long arr[101] = {0, 1, 1, };
//
//long long go(int n){
//	if(n < 3){
//		return arr[n];
//	}
//	if(arr[n] == 0){
//		arr[n] = go(n - 3) + go(n - 2);
//	}
//	
//	return arr[n];
//}
//
//int main(){
//	
//	int t, n;
//	cin >> t;
//	for(int i=0; i<t; i++){
//		cin >> n;
//		cout << go(n) << '\n';
//	}
//	
//	return 0;
//}
