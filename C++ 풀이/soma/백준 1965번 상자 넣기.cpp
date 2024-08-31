#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int ret = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) { // 이전에 탐색한 거 한번씩 탐색 n이 1000 이기에 가능 
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++; // i가 지날수록 어차피 박스 크기는 +됨
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	return 0;
}
