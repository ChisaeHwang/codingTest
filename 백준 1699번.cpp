#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000];
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 

	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		dp[i] = i;
		for(int j=1; j*j<=i; j++){
			if(dp[i] > dp[i-j*j]+1){
				dp[i] = min(dp[i], dp[i-j*j]+1);
			}
		}
	}
	
	cout << dp[n];
	
    return 0;
}

  
