#include <iostream>
#include <cstring>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

// 0 : ²ªÀ» ¼ö ÀÖÀ½. 1 : ²ªÀ» ¼ö ¾øÀ½
int dp[110][110][2][2]; //dir, 1 or over2
int ans = 0, w, h, mod = 100000;

int main(){
    fast;
    cin >> w >> h;

    for (int i = 2; i <= w; i++) dp[i][1][0][0] = 1;
    for (int i = 2; i <= h; i++) dp[1][i][1][0] = 1;
    for (int i = 2; i <= w; i++) {
        for (int j = 2; j <= h; j++) {
            dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % mod;
            dp[i][j][0][1] = dp[i-1][j][1][0];
            dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % mod;
            dp[i][j][1][1] = dp[i][j-1][0][0];
        }
    }
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ans += dp[w][h][i][j];
    cout << ans % mod;


  return 0;
}

