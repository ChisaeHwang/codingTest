#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][3]; // 상태를 나타내는 인덱스를 마지막에 위치
int arr[1001][1001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<3; k++) {
                if(k == arr[i][j]) {
                    int next = (k + 1) % 3;
                    if(dp[i-1][j][k] != 0) {
                        dp[i][j][next] = max(dp[i-1][j][k] + 1, dp[i][j][next]);
                    }
                    if(dp[i][j-1][k] != 0) {
                        dp[i][j][next] = max(dp[i][j-1][k] + 1, dp[i][j][next]);
                    }
                    
                    if(dp[i-1][j][k] == 0 && arr[i][j] == 0) {
                        dp[i][j][next] = max(dp[i][j][next], 1);
                    }
                    if(dp[i][j-1][k] == 0 && arr[i][j] == 0) {
                        dp[i][j][next] = max(dp[i][j][next], 1);
                    }
                }               
                dp[i][j][k] = max({dp[i][j][k], dp[i-1][j][k], dp[i][j-1][k]});
            }
        }
    }
    
    int result = max({dp[n][n][0], dp[n][n][1], dp[n][n][2]});
    cout << result << "\n";
    
    return 0;
}

