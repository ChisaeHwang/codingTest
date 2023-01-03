#include <bits/stdc++.h>

using namespace std;

// top down ������� Ǯ�� ������ �Ʒ��� 
int n, dp[1000001]; // �� idx�� ���� �� �ִ� �ּ� ����� �� 

int go(int n) {
	
	if (n == 1) return 0; //�⺻ ���̽� 
	if (dp[n] != -1) return dp[n]; // �̹� ����� �� 


	int ret = go(n - 1) + 1;
	if (n % 3 == 0) ret = min(ret, go(n / 3) + 1);
	if (n % 2 == 0) ret = min(ret, go(n / 2) + 1);
	dp[n] = ret;
	
	return ret; 
}

int main() {
	
	cin >> n;
	
	fill(dp, dp + 1000001, -1);
	
	cout << go(n) << '\n';
	
	return 0;	
}
