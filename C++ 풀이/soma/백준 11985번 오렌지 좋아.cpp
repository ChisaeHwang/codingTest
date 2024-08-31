#include <bits/stdc++.h>

const long long INF = 1e18;

using namespace std;

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> A(N + 1);
    for (long long i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> dp(N + 1, INF);
    dp[0] = 0;
    
    for (long long i = 1; i <= N; ++i) {
        long long max_a = -1;
        long long min_a = LLONG_MAX;
        
        for (long long j = 1; j <= M && i - j >= 0; ++j) {
            max_a = max(max_a, A[i - j + 1]);
            min_a = min(min_a, A[i - j + 1]);
            long long s = j;
            long long cost = K + s * (max_a - min_a);
            dp[i] = min(dp[i], dp[i - j] + cost);
        }
    }
    
    cout << dp[N] << '\n';
    
    return 0;
}

