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
	
    // n-2 ���� ����ؼ� n-1�� ���� �� �ִ� ����� �� 
    // N - 1��° ���ڴ� ���;� �ϴ� ����̹Ƿ� N - 2 ������ �ε����� Ȯ���ϸ� �ȴ�.
	
	return 0;
}
