#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int dp_up[1001][1001]; // 상승 비행을 위한 DP 테이블
int dp_down[1001][1001]; // 하강 비행을 위한 DP 테이블
int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 상승 비행 점수 계산
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp_up[i][j] = arr[i][j];
            if(i > 0) dp_up[i][j] = max(dp_up[i][j], dp_up[i-1][j] + arr[i][j]);
            if(j > 0) dp_up[i][j] = max(dp_up[i][j], dp_up[i][j-1] + arr[i][j]);
        }
    }

    // 하강 비행 점수 계산
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            dp_down[i][j] = arr[i][j];
            if(i < n-1) dp_down[i][j] = max(dp_down[i][j], dp_down[i+1][j] + arr[i][j]);
            if(j < m-1) dp_down[i][j] = max(dp_down[i][j], dp_down[i][j+1] + arr[i][j]);
        }
    }

    int max_score = arr[0][m-1]; // 상승과 하강이 만나는 지점의 점수로 초기화
    // 최대 점수 계산
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 상승과 하강이 만나는 지점에서만 최대 점수를 갱신
            if(dp_up[i][j] + dp_down[i][j] - arr[i][j] > max_score) {
                max_score = dp_up[i][j] + dp_down[i][j] - arr[i][j];
            }
        }
    }

    cout << max_score << endl;

    return 0;
}

