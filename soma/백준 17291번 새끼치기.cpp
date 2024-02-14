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
		 
		 if(i % 2 == 0) { // 문제를 읽어보면 어차피 짝수일때만 사망함 
		 	 dp[i] -= dp[i - 5] + dp[i - 4];
		 } // 원래는 dp[i - 4] + dp[i - 3] 번째를 2로 나눠서 하는게 더 직관적이지만 
	}  // 홀수일 경우를 생각해서 -1씩 더 추가해서 없애주면 정답 
	
	cout << dp[n] << '\n';

    return 0;
}

