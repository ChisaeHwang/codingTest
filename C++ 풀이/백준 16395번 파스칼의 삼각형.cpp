#include <bits/stdc++.h>
using namespace std;
int d[31][31];
int main()
{
    for (int i = 0; i < 31; i++)
    {
        d[i][0] = 1;
    }
    for (int i = 1; i < 31; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }
    int a, b;
    cin >> a >> b;
    cout << d[a - 1][b - 1] << '\n';
}