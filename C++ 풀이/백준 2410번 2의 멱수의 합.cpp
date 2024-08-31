#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>

using namespace std;

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;

    // Process
    int dp[N+1]; /* dp[i] = i 를 2의 멱수의 합으로 나타내는 경우의 수 */
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    for (int i=2; i<=N; i++) {
        dp[i] += dp[i-1];
        if (i%2 == 0) { /* i 가 짝수인 경우 */
            dp[i] += dp[i/2];
            dp[i] %= 1000000000;
        }
    }

    // Control : Output
    cout << dp[N] << '\n';
    
    return 0;
}


