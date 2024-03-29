#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool ok = false;
        for (int k = x; k < (n * m); k += m)
        {
            if (k % n == y)
            {
                cout << k + 1 << '\n';
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}