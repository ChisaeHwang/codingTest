#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[101][101][101];

int main() {
	
	string n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	
	int f = n1.length(), s = n2.length(), t = n3.length();
	
	for(int i = 1; i <= f; i++){
		for(int j = 1; j <= s; j++){
			for(int k = 1; k <= t; k++){
				if (n1[i-1] == n2[j-1] && n2[j-1] == n3[k-1]){
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				} else {
					dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
				}
			}
		}
	}
	
	cout << dp[f][s][t] << '\n';
	
	return 0; 
} 
