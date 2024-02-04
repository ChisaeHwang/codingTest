#include <bits/stdc++.h>

using namespace std;

struct Wire {
    int a, b;
};

bool compare(Wire w1, Wire w2) {
    return w1.a < w2.a;
}

int main() {
    int n; 
    cin >> n;
    vector<Wire> wires(n);
    for (int i = 0; i < n; i++) {
        cin >> wires[i].a >> wires[i].b;
    }

    sort(wires.begin(), wires.end(), compare);

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (wires[i].b > wires[j].b && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // LIS�� �ִ� ���̸� ã��
    int maxLength = *max_element(dp.begin(), dp.end());

    // ��� ��� (��ü ������ ���� - LIS ����)
    cout << n - maxLength << '\n';

    return 0;
}
