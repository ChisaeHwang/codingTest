#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dp[100001]; 
int coin[101];
int main()
{

    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i] = 100001;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= m; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[m] == 100001)
        cout << -1 << '\n';
    else
        cout << dp[m] << '\n';

    return 0;
}