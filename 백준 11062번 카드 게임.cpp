#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>

using namespace std;

int dp[1001][1001];
int arr[1001];

int go(int left, int right, int turn) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (turn % 2) // ±Ù¿ì Â÷·Ê
	   return dp[left][right] = max(arr[left] + go(left + 1, right, turn + 1), arr[right] + go(left, right - 1, turn + 1));
	else // ¸í¿ì Â÷·Ê 
	   return dp[left][right] = min(go(left + 1, right, turn + 1), go(left, right - 1, turn + 1));
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
	
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		go(0, n - 1, 1);
		cout << dp[0][n - 1] << '\n';
		
		memset(dp, 0, sizeof(dp));
		
	}
	
	return 0;
}
