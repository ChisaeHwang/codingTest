#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int dp[10001][501][2]; // �ð�, ��ħ����, �޸��� ���� 0 : ���� ���, 1 : �޸��� ��� 
int n, m;

int main() {
	
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0][1][1] = arr[0];  

   for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
        	// �� �޸��� ��� 
        	if(j + 1 <= m) {
        	 dp[i][j][0] = max({dp[i - 1][j][0], dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]});	
			} 
			
			// �޸��� ��� 
            if(j > 0){ 
                dp[i][j][1] = dp[i - 1][j - 1][1] + arr[i];
                if(j == 1) dp[i][j][1] = max({dp[i][j][1], dp[i - 1][0][0] + arr[i]});
            }
        }
    }	
    
    cout << dp[n - 1][0][0] << '\n';

    return 0;
}

