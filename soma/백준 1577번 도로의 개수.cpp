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
        // 공사 중인 도로 표시: 오른쪽 또는 아래로 이동 불가능한 경우
        if (a == c && b+1 == d) rightBlocked[a][b] = true;
        if (a+1 == c && b == d) downBlocked[a][b] = true;
        if (a == c && d+1 == b) rightBlocked[c][d] = true;
        if (c+1 == a && b == d) downBlocked[c][d] = true;
    }

    dp[0][0] = 1; // 시작 지점 초기화
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0 && !downBlocked[i-1][j]) dp[i][j] += dp[i-1][j]; // 위쪽에서 오는 경우
            if (j > 0 && !rightBlocked[i][j-1]) dp[i][j] += dp[i][j-1]; // 왼쪽에서 오는 경우
        }
    }

    cout << dp[n][m] << '\n'; // 최종 경로의 수 출력

    return 0;
}

