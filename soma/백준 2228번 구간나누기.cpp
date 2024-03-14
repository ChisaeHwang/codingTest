#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][101];
int arr[101];
int n, m;

int main() {
	
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
    	int num;
    	cin >> num;
    	arr[i] = arr[i - 1] + num;
	}

	for(int j = 1; j <= m; j++) {
	    dp[0][j] = -987654321; // 불가능한 경우 초기화 
	}

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j]; // 일단 i - 1번째 값 가져오기
            if(j == 1) {
                // 첫 번째 구간에 대한 최대 합을 초기화
                dp[i][j] = max(dp[i][j], arr[i]);
            }
            for(int k = 2; k <= i; k++) {
                dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + arr[i] - arr[k - 1]);
            }
        }
    }
	
	cout << dp[n][m] << '\n';

    return 0;
}

