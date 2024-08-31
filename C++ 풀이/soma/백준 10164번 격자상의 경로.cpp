#include <bits/stdc++.h>
using namespace std;

int dp[16][16]; 

int solve(int sx, int sy, int ex, int ey) {
	
    memset(dp, 0, sizeof(dp));
    dp[sx][sy] = 1; // 시작 지점

    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (i > sx) dp[i][j] += dp[i-1][j];
            if (j > sy) dp[i][j] += dp[i][j-1];
        }
    }

    return dp[ex][ey];
}


int main() {
	
    int n, m, k;
    cin >> n >> m >> k;

 	int ret = 0;
    if (k == 0) {
        ret = solve(0, 0, n-1, m-1);
    } else {
        k--; // 문제는 1으로 시작하지만, 배열은 0부터 시작 
        int kn = k / m;
		int km = k % m;
        int AtoB = solve(0, 0, kn, km);
        int BtoC = solve(kn, km, n-1, m-1);
        ret = AtoB * BtoC;
    }

    cout << ret << endl;

    return 0;
}

