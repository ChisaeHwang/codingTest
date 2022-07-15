#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

long long arr[101];
long long dp[101][21];

int main() {
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	dp[0][arr[0]] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 20; j++){
			if(j - arr[i] >= 0){
				dp[i][j] += dp[i-1][j-arr[i]];
			}
			
			if(j + arr[i] < 21){
				dp[i][j] += dp[i-1][j+arr[i]];
			}
		}
	}
	
	cout << dp[n-2][arr[n-1]] << '\n';
	
    // n-2 까지 사용해서 n-1가 나올 수 있는 경우의 수 
    // N - 1번째 숫자는 나와야 하는 결과이므로 N - 2 까지의 인덱스만 확인하면 된다.
	
	return 0;
}
