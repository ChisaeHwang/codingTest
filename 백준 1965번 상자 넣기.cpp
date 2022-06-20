#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
	
	int n, ans = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	} 
	
	dp[0] = 1;
	
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){ // n이랑 n-1를 비교 
			if(arr[i] > arr[j]){  
				dp[i] = max(dp[i], dp[j]); // 최댓값 구하기 
			}
		}
		dp[i] += 1; // 상자 하나씩 추가 
		ans = max(ans, dp[i]);
	}
	
	cout << ans << '\n';
	
	return 0;
} 
