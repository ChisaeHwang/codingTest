#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int p[10001];
int n;

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
			// i - j�� ���� �� dp[i]���� �ִ밪���� ������
			// -> �װ͵��� �״�� �޸𸮶���¡ ���־� �ְ����� ���� 
		}
	}
	
	cout << dp[n] << '\n';
	
	
	return 0;
}
