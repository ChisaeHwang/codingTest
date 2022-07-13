#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[31][31];   // 온전한 알약 W개, 반쪽짜리 알약 H개 

int main() {

	for(int i = 0; i < 31; i++){
		dp[0][i] = 1;
	} 
	
	while(true){
		cin >> n;
		if(n == 0) return 0;
		
		for(int w = 1; w < n; w++){
			for(int h = 0; h < n; h++){
				if(h == 0){ // 반쪽 알약이 없을 경우 
					dp[w][h] = dp[w-1][1];
				} else {
					dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
				}
			}
		}
		
		// W : n - 1개, H : 1개의 값을 구하면 됨 
		cout << dp[n-1][1] << '\n';
	}
	
	return 0;
}
