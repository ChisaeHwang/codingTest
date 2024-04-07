#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int n, m;

int main() {
    
    cin >> n >> m; // n은 행의 개수, m은 열의 개수
    
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int ret = 0;
    
    for(int i = 0; i < n; i++) { // n은 행의 개수
        for(int j = 0; j < m; j++) { // m은 열의 개수
            if(arr[i][j] == 0) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    // 왼쪽, 윗쪽, 왼쪽 대각선 중에 하나라도 돌이 있으면 이 부분은 0이므로
					// 다시 초기화해서 dp가 갱신됨
					// 즉 왼쪽, 윗쪽, 왼쪽 대각선이 0(들판)인 상태여야지 1씩 +해서 갱신 가능 
                }
                ret = max(ret, dp[i][j]);
            }
        }
    }
    
    cout << ret << '\n';

    return 0;
}

