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
    int dp[N+1]; /* dp[i] = i �� 2�� ����� ������ ��Ÿ���� ����� �� */
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    for (int i=2; i<=N; i++) {
        dp[i] += dp[i-1];
        if (i%2 == 0) { /* i �� ¦���� ��� */
            dp[i] += dp[i/2];
            dp[i] %= 1000000000;
        }
    }

    // Control : Output
    cout << dp[N] << '\n';
    
    return 0;
}


