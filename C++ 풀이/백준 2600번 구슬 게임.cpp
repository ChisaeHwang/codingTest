#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int b[3];
int dp[501][501][2]; 

int go (int p, int q, int w){
	if( dp[p][q][w] >= 0 ) return dp[p][q][w];
    if( p + q == 0 ) return dp[p][q][w]=0;
    
    for(int i = 0; i < 3; i++){
    	if(b[i] <= p && !go(p - b[i], q, 1 - w)) {
    		return dp[p][q][w] = 1;
		}
	}
	
	for(int i = 0; i < 3; i++){
    	if(b[i] <= q && !go(p, q - b[i], 1 - w)) {
    		return dp[p][q][w] = 1;
		}
	}
	
	return dp[p][q][w] = 0;
}

int main() {
	
	for(int i = 0; i < 501; i++){
		for(int j = 0; j < 501; j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
	
	cin >> b[0] >> b[1] >> b[2];
	
	for(int t = 0; t < 5; t++){
		int k1, k2;
		cin >> k1 >> k2;
		if(go(k1, k2, 1)){
			cout << "A" << '\n';
		} else {
			cout << "B" << '\n';
		}
	}
	

	return 0;
} 
