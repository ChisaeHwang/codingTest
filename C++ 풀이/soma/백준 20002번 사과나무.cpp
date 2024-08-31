#include <bits/stdc++.h>

using namespace std;

int dp[301][301];
int arr[301][301];
int n;

int main() {
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (i == 0 && j == 0) {
                dp[i][j] = arr[i][j]; 
            } else if (i == 0) {
                dp[i][j] = dp[i][j-1] + arr[i][j]; 
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] + arr[i][j]; 
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
            }
		}
	}
	
	int ret = INT_MIN; 

    for (int k = 1; k <= n; k++) {
        for (int i = k-1; i < n; i++) {
            for (int j = k-1; j < n; j++) {
                int temp = dp[i][j];
                if (i >= k) temp -= dp[i-k][j]; // 위쪽 삭제 
                if (j >= k) temp -= dp[i][j-k]; // 왼쪽 삭제 
                if (i >= k && j >= k) temp += dp[i-k][j-k]; // ㄱ벼쳐서 밴 부분 다시 더하기 
                ret = max(ret, temp); 
            }
        }
    }
    
    cout << ret << '\n'; 
	
	return 0;
}
