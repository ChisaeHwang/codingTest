#include <bits/stdc++.h>
using namespace std;

int n;
int dp[21];

int main() {
	
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;
    dp[5] = 14;
    
    for(int i = 6; i <= n; i++) {
		 dp[i] = dp[i - 1] + dp[i - 1];
		 
		 if(i % 2 == 0) { // ������ �о�� ������ ¦���϶��� ����� 
		 	 dp[i] -= dp[i - 5] + dp[i - 4];
		 } // ������ dp[i - 4] + dp[i - 3] ��°�� 2�� ������ �ϴ°� �� ������������ 
	}  // Ȧ���� ��츦 �����ؼ� -1�� �� �߰��ؼ� �����ָ� ���� 
	
	cout << dp[n] << '\n';

    return 0;
}

