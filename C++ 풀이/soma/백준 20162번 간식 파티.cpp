#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];
int n;

int main() {
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
    	dp[i] = arr[i];
	}
	
	int ret = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) { // 가장 긴 증가하는 부분 수열... 
				dp[i] = max(dp[i], arr[i] + dp[j]);
			}
		}
		
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
    
    return 0;
}

