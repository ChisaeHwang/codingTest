#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;
long long dp[MAX][MAX]; 
bool rightBlocked[MAX][MAX];
bool downBlocked[MAX][MAX];
int n, m, k;

int main() {
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // ���� ���� ���� ǥ��: ������ �Ǵ� �Ʒ��� �̵� �Ұ����� ���
        if (a == c && b+1 == d) rightBlocked[a][b] = true;
        if (a+1 == c && b == d) downBlocked[a][b] = true;
        if (a == c && d+1 == b) rightBlocked[c][d] = true;
        if (c+1 == a && b == d) downBlocked[c][d] = true;
    }

    dp[0][0] = 1; // ���� ���� �ʱ�ȭ
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0 && !downBlocked[i-1][j]) dp[i][j] += dp[i-1][j]; // ���ʿ��� ���� ���
            if (j > 0 && !rightBlocked[i][j-1]) dp[i][j] += dp[i][j-1]; // ���ʿ��� ���� ���
        }
    }

    cout << dp[n][m] << '\n'; // ���� ����� �� ���

    return 0;
}

