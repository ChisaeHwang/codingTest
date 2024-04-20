#include <bits/stdc++.h>
#define INF -987654321

using namespace std;

int arr[10001];
int dp[10001][501]; // 시간, 지침지수, 달리는 여부 0 : 쉬는 경우, 1 : 달리는 경우 
int N, M;

int solve(int n, int m) {
	
	 if(n == N) {
        if(m == 0) return 0;
        return INF;
    }
    
    int& ret = dp[n][m];
    if(ret != -1) return ret;
    
	ret = INF;
    
    if(m > 0) {
        if(n + m <= N) {
			ret = max(ret, solve(n + m, 0));
		}
    }else {
        ret = max(ret, solve(n + 1,0));
    }
 
    if(m + 1 <= M) {
    	ret = max(ret, solve(n + 1,m + 1) + arr[n]);
	}
    return ret;
	
}

int main() {
	
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
     memset(dp, -1 ,sizeof(dp));
    
    cout << solve(0, 0) << '\n';
    
    return 0;
}

