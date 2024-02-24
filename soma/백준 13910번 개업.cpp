#include <bits/stdc++.h>

using namespace std;

int dp[10001]; // �׸��� ����µ� ���Ǵ� �ּ� Ƚ�� 
int wok[101];
const int MAX = 987654321;

int main() {
	
	int n, m;
	
	cin >> n >> m;
	
    for(int i = 0; i <= n; i++) {
        dp[i] = MAX;
    }
	
	for(int i = 0; i < m; i++) {
		cin >> wok[i];
	}
	
	sort(wok, wok + m, greater<int>());
	
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
   			 // �� ���� ���� ����ϴ� ���
            if (i >= wok[j]) {
                dp[i] = min(dp[i], dp[i - wok[j]] + 1);
            }
            
            // �� ���� ���� ����ϴ� ���
            for (int k = j + 1; k < m; k++) { // j�� k�� �������� �� ���� �� ���
                if (i >= (wok[j] + wok[k])) {
                    dp[i] = min(dp[i], dp[i - (wok[j] + wok[k])] + 1);
                }
            }
		}
	}
	
  	if (dp[n] == MAX) {
        cout << -1 << '\n'; 
    } else {
        cout << dp[n] << '\n'; 
    }
	
	return 0;
}
