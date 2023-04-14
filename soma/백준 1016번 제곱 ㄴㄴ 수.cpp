#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 1000001;
vector<int> primes;

void init() {
    vector<bool> is_prime(MAX_N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool isSqnn(int n) {
    int sqrt_n = sqrt(n);
    for (int prime : primes) {
        if (prime > sqrt_n) break;
        if (n % (prime*prime) == 0) return false;
    }
    return true;
}

int main() {
    init();
    int minNum, maxNum;
    cin >> minNum >> maxNum;
    int cnt = 0;
    for (int i = minNum; i <= maxNum; i++) {
        if (isSqnn(i)) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}

