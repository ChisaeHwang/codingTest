#include <bits/stdc++.h>

using namespace std;

int n, ret = -10011;
int arr[100001];
int dp[100001]; // ���� index���� ���� ū �� 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		if (dp[i] < dp[i - 1] + arr[i]) { // dp[i - 1]�� ������ ��� ó�� 
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			// ���� �� �� ���ϱ�, ���� �� ���ϱ� 
		}
		
		ret = max(ret, dp[i]);
	}
	
	cout << ret;
	
	
	return 0;
}
