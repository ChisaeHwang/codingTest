#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = {0, }; // 현재 위치
int arr[1001] = {0, }; 

int main(){
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	dp[1] = 1;
	
	for(int i=1; i<=n; i++){
		
		if (dp[i] == 0) {
			break;
		}
		
		for(int j=1; j<=arr[i]; j++){
			if(dp[i+j] > dp[i]+1 || dp[i+j] == 0){
				dp[i+j] = dp[i]+1;
			}
		}
	}
	
	if(dp[n] == 0){
		cout << -1 << '\n';
	} else {
		cout << dp[n] - 1 << '\n';	
	}
	
	return 0;
}
