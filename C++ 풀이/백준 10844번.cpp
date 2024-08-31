#include <iostream>
#define mod 1000000000

using namespace std;

int d[101][11] = {0, };

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=9; i++){ // 1, 2, 3, 4, 5, 6 ...
    	d[1][i] = 1;
	}
    for(int i=2; i<=n; i++){ // n의 2의 길이 일때 
    	for(int j=0; j<=9; j++){ // 10, 12, 21, 23, 32, 34, 43, 45 ....
    		if(j-1 >= 0){
    			d[i][j] += d[i-1][j-1]; // 10, 21, 32, 43 ....
			}
			if(j+1 <= 9){
				d[i][j] += d[i-1][j+1]; // 12, 23, 34, 45 ....
			}
			d[i][j] %= mod; // 오버플로우 방지 위해 % 연산 
		}
	}
	
	long long ans = 0; // 오버플로우 방지하기 위해 long long 
	for (int i=0; i<=9; i++){
		ans += d[n][i]; // dp[1] 1 1 2 2 2 2 2 2 2 1 = 17
	}
	
	ans %= mod;
	
	cout << ans;
	
    
    return 0;
}

 
