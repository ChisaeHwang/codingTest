#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[1001][1001]; 

int main() {
	
	string from, to;
	cin >> from >> to;
	
	int maxL = max(from.length(), to.length());
	
	for (int i = 1; i <= maxL; i++){
		dp[0][i] = i;
		dp[i][0] = i;
	}
	
	for (int i = 1; i <= to.length(); i++){
		for (int j = 1; j <= from.length(); j++){
			// 문자열 인덱스는 0부터ㅑ 시작하므로 i - 1, j - 1부터 시작 
			if(from[j - 1] == to[i - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	
	cout << dp[to.length()][from.length()] << '\n';
	
	return 0;
}
