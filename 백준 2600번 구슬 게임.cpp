#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int b[3];
int dp[501][501][2]; 

int go (int p, int q, int w){
	if( dp[p][q][w] >= 0 ) return dp[p][q][w];
    if( p + q == 0 ) return dp[p][q][w]=0;
}

int main() {
	

	return 0;
} 
