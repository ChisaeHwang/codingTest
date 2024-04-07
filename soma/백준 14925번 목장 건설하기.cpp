#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int n, m;

int main() {
    
    cin >> n >> m; // n�� ���� ����, m�� ���� ����
    
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int ret = 0;
    
    for(int i = 0; i < n; i++) { // n�� ���� ����
        for(int j = 0; j < m; j++) { // m�� ���� ����
            if(arr[i][j] == 0) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    // ����, ����, ���� �밢�� �߿� �ϳ��� ���� ������ �� �κ��� 0�̹Ƿ�
					// �ٽ� �ʱ�ȭ�ؼ� dp�� ���ŵ�
					// �� ����, ����, ���� �밢���� 0(����)�� ���¿����� 1�� +�ؼ� ���� ���� 
                }
                ret = max(ret, dp[i][j]);
            }
        }
    }
    
    cout << ret << '\n';

    return 0;
}

