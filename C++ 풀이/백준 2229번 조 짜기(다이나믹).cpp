#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

int dp[10001];
int arr[10001];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	dp[0] = 0;
	dp[1] = 0;
	
	for(int i = 2; i <= n; i++){
		dp[i] = max(abs(arr[i] - arr[i-1]), abs(arr[i-1] - arr[i-2]));
		dp[i] = dp[i] + dp[i-1];
	}
	
	
	cout << dp[n] << '\n';
	
	return 0;
}
