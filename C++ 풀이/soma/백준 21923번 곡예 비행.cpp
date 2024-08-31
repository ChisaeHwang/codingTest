#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int dp_up[1001][1001]; // ��� ������ ���� DP ���̺�
int dp_down[1001][1001]; // �ϰ� ������ ���� DP ���̺�
int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // ��� ���� ���� ���
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp_up[i][j] = arr[i][j];
            if(i > 0) dp_up[i][j] = max(dp_up[i][j], dp_up[i-1][j] + arr[i][j]);
            if(j > 0) dp_up[i][j] = max(dp_up[i][j], dp_up[i][j-1] + arr[i][j]);
        }
    }

    // �ϰ� ���� ���� ���
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            dp_down[i][j] = arr[i][j];
            if(i < n-1) dp_down[i][j] = max(dp_down[i][j], dp_down[i+1][j] + arr[i][j]);
            if(j < m-1) dp_down[i][j] = max(dp_down[i][j], dp_down[i][j+1] + arr[i][j]);
        }
    }

    int max_score = arr[0][m-1]; // ��°� �ϰ��� ������ ������ ������ �ʱ�ȭ
    // �ִ� ���� ���
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // ��°� �ϰ��� ������ ���������� �ִ� ������ ����
            if(dp_up[i][j] + dp_down[i][j] - arr[i][j] > max_score) {
                max_score = dp_up[i][j] + dp_down[i][j] - arr[i][j];
            }
        }
    }

    cout << max_score << endl;

    return 0;
}

