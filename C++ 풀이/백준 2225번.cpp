#include <iostream>
#include <algorithm>
#define mod 1000000000

using namespace std;

int n, k;
long long dp[201][201] = {0}; //dp[K][N] => K개로 N만들기
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	
	dp[0][0] = 1LL; // long long
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			for(int l=0; l<=j; l++){
				dp[i][j] += dp[i-1][j-l];
				dp[i][j] %= mod;
			}
		}
	}
	
	cout << dp[k][n] << '\n';

	
    return 0;
}
