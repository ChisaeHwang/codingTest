#include <bits/stdc++.h>

using namespace std;

int dp[10001]; // 그릇을 만드는데 사용되는 최소 횟수 
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
   			 // 한 개의 웍만 사용하는 경우
            if (i >= wok[j]) {
                dp[i] = min(dp[i], dp[i - wok[j]] + 1);
            }
            
            // 두 개의 웍을 사용하는 경우
            for (int k = j + 1; k < m; k++) { // j와 k의 조합으로 두 개의 웍 사용
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
