#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int dp[4][50001];

int arr[50001];

int main() {
	
	int n, m, temp;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> temp;
		arr[i] = arr[i-1] + temp;
	}
	
	cin >> m;
	
	for(int i = 1; i <= 3; i++){
		for(int j = i * m; j <= n; j++){
			// ���� ���������� �ִ밪, ���� ������ �������� �� �ִ밪 
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + arr[j] - arr[j - m]); // ������ j - k ���� 
		}
	}
	
	cout << dp[3][n] << '\n';
	
	
	return 0;
}
