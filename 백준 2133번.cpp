#include <iostream>
#include <algorithm>

using namespace std;

int D[31]= {1, 0, 3};

dp[n] = dp[n - 1] + dp[n - 2]

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    if(n%2==0){
        for(int i = 4; i <= n; i += 2){
    		D[i] = 3*D[i - 2];
    		for(int j = 4; j <= i; j += 2){
    			if(j % 2 == 0){
        			D[i] += 2*D[i - j];		
				}
			}
		}
	}
	
	cout << D[n];
	
    return 0;
    
}
