#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];
int coin[25];

int main() {
	
	int t;
	cin >> t; 
	while(t--){
		int n, m;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> coin[i];
		}
		cin >> m;
		
		for(int i= 1 ; i < m+1; i++){
			dp[i] = 0;
		}
		dp[0] = 1;
		
		for(int i = 0; i < n; i++){ // 동전 종류만큼 반복문을 돌기
		 // 선택된 동전이 a[i]원짜리의 동전이면 a[i] ~ 목표금액 만큼 돌기 
			for(int j = coin[i]; j <= m; j++){
				// j원을 만들수 있는 가짓수 += (j - a[i])원을 만들수 있는 가짓수
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
		
		cout << dp[m] << '\n';
	}
	
	
	
	return 0;
}
