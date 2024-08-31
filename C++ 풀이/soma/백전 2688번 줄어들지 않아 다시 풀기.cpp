#include <iostream>
using namespace std;


long long comb(int n, int r) {
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - r + i);
        result /= i;
    }
    return result;
}

long long solve(int n) {
    return comb(n + 9, 9);
}

int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n; 
        cout << solve(n) << '\n'; 
    }
    return 0;
}

