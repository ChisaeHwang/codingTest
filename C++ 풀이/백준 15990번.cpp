#include <iostream>
#define MOD 1000000009

using namespace std;

long long dp[100001][4];
long long add(int num){
	for(int i=4; i<=num; i++){
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}
	
	return (dp[num][1] + dp[num][2] + dp[num][3]) % MOD;
	
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    int t, n;
    cin >> t;
    
    while(t--){
    	cin >> n;
    	cout << add(n) << '\n';
	}

    return 0;
}

 
