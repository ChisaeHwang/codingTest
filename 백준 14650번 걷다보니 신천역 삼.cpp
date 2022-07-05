#include <iostream>
using namespace std;
 
 
int main(void) {
    int n;
    int dp[1005][3];
    cin >> n;
 
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        }
    }
 
    cout << dp[n][0] << '\n';
}

