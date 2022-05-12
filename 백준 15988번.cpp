#include <iostream>
#define MAX 1000000
#define MOD 1000000009

using namespace std;

long long dp[MAX + 1];
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=MAX; i++){
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
	}

    int t, n;
    cin >> t;
    
    while(t--){
    	cin >> n;
    	cout << dp[n] << '\n';
	}

    return 0;
}

 
