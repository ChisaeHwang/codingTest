#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int reTryNum = 0;
    
    cin >> reTryNum;
    
    for (int t = 0; t < reTryNum; t++) {

        int a, b, sum = 1;
        cin >> a >> b;

        for (int i = 0; i < b; i++) {
            sum = sum * a;
            
            sum = sum % 10;
        }
        if (sum == 0) {
            cout << 10 << '\n';
        }
        else {
            cout << sum << '\n';
        }

    }

    return 0;
}
