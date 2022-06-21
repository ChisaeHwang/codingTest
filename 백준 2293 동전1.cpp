#include <iostream>
#include <queue>
using namespace std;

int dp[10001] = {0}; // 초기화
int coin[101];
int main()
{

    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= coin[i])
            {
                dp[j] += dp[j - coin[i]];
            }
        }
    }

    cout << dp[m] << '\n';

    return 0;
}