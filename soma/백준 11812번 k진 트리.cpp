#include <iostream>
using namespace std;

long long findDepth(long long x, long long K) {
    long long depth = 0;
    while (x != 1) {
        x = (x - 2) / K + 1;
        depth++;
    }
    return depth;
}

long long findDistance(long long x, long long y, long long K) {
    long long distance = 0;
    while (x != y) {
        if (x > y) {
            x = (x - 2) / K + 1;
            distance++;
        } else {
            y = (y - 2) / K + 1;
            distance++;
        }
    }
    return distance;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long N, K, Q;
    cin >> N >> K >> Q;
    for (long long i = 0; i < Q; i++) {
        long long x, y;
        cin >> x >> y;
        cout << findDistance(x, y, K) << '\n';
    }
    return 0;
}

