#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2001];
int dp[2001];

int main() {
	
    cin >> n;
    
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
	}
	
	// dp 배열의 모든 요소를 1로 초기화
    fill(dp, dp + n, 1);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	int maxLen = 0;
	
	for(int i = 0; i < n; i++) {
		maxLen = max(maxLen, dp[i]);
	}
 	
	cout << n - maxLen << '\n';
    
    return 0;
}

