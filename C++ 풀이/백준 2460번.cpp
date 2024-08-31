#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0, sum = 0, inN, outN, n = 10;

    for (int i = 0; i < n; i++)
    {
        cin >> outN >> inN;
        sum -= outN;
        sum += inN;
        if (result < sum)
        {
            result = sum;
        }
    }

    cout << result;

    return 0;
}