#include <iostream>
using namespace std;


int main()
{
    int N, L;
    cin >> N >> L;

    for (int i = L; i <= 100; i++)
    {
        int temp = N - i * (i + 1) / 2;

        if (temp % i == 0)
        {
            int j = temp / i + 1;

            if (j >= 0)
            {
                for (int k = 0; k < i; k++)
                {
                    cout << k + j << " ";
                }
                cout << "\n";

                return 0;
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}