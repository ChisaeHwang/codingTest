#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001] = {
    0,
};
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[num] += 1;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++) // arr[] 안에 있는 숫자들만 순회 하도록
        {
            cout << i << '\n';
        }
    }

    return 0;
}