#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> topics(N);  // (���νð�, ����)
    for (int i = 0; i < N; i++) {
        cin >> topics[i].first >> topics[i].second;
    }

    vector<int> dp(T + 1, 0);  // �� �ð��� ���� �ִ� ����
    for (int i = 0; i < N; i++) {
        int study_time = topics[i].first;
        int score = topics[i].second;
        for (int j = T; j >= study_time; j--) {
            dp[j] = max(dp[j], dp[j - study_time] + score);
        }
    }

    cout << dp[T] << endl;
    return 0;
}

