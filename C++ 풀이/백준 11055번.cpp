#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int arr[1001];
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, ans=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		dp[i] = arr[i]; // 길이 증가가 아닌 합 증가 이므로 
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) { // j < i 이다  
				dp[i] = max(dp[i], dp[j] + arr[i]); // 길이에서 합 증가로 바꿔짐 
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	
	return 0;
}
