#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int dp[1001][1001];

int main() {
	
	string n1, n2;
	cin >> n1 >> n2;
	
	int f = n1.length(), s = n2.length();
	
	for(int i = 1; i <= f; i++){
		for(int j = 1; j <= s; j++){
			// 두 문자가 같다면 dp[i - 1][j - 1]값에 + 1 한다 
			if(n1[i - 1] == n2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				// 두 문자가 다를 경우에는 가장 큰 값을 표시한다. 
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[f][s] << '\n';
	
	
	return 0;
}
