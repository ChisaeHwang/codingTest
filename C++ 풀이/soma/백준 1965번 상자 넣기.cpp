#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int ret = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) { // ������ Ž���� �� �ѹ��� Ž�� n�� 1000 �̱⿡ ���� 
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++; // i�� �������� ������ �ڽ� ũ��� +��
		ret = max(ret, dp[i]);
	}
	
	cout << ret << '\n';
	
	return 0;
}
