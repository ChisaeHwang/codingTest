#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#define MOD 10001

using namespace std;

// i번쨰 앱까지 확인할 때 j의 비용으로 얻을 수 있는 최대 메모리 
int dp[101][MOD];
int arr[101];
int c[101];
 

int main() {
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < MOD; j++){
			if(j - c[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + arr[i]);	
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	
	for(int i = 0; i <= MOD; i++){
		if(dp[n][i] >= m){
			cout << i << '\n';
			return 0;
		}
	}
	
}
