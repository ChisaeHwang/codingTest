#include <iostream>
#include <algorithm>

using namespace std;

int dp [1001][3];
int cost[1001][3];
int main(){
	
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<3; j++){
			cin >> cost[i][j];
		}
	}
	
	int ans = 1000*1000 + 1;
	for(int k=0; k<=2; k++){ // 1������ ��(k)�� ���� �� �� �ֱ� 
		for(int j=0; j<=2; j++){
			if(j == k){
				dp[1][j] = cost[1][j];
			} else {
				dp[1][j] = 1000*1000+1;
			}
		}
	
		for(int i=2; i<=N; i++){
	 		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
	        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
	        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
		}
		
		for(int j=0; j<=2; j++){ // j�� n������ ���� �ǹ��� 
			if(j == k){ // 1������ n��° ���� ���� ��� �ǳʶٱ� 
				continue;
			}
			ans = min(ans, dp[N][j]);
		}
	}
	
  cout << ans << '\n';
	
}
