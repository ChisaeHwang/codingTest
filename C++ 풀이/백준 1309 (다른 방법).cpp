#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int s[100001];

int main(){
	
	int N;
	cin >> N;
	dp[0] = s[0] = 1; // dp[0]�� ä��� ����� �ϳ� �ִ� 
	dp[1] = 2; // dp[1]���� O X / X O ��� �������� �ִ� 
	s[1] = dp[0] + d[1]; // s�� dp�� ���� �����ϴ� �� �̱⿡ dp[0] + dp[1] �� �����ָ� �� 
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + 2*s[i-2];
		s[i] = s[i-1] + dp[i]; // s�� d[0]���� d[i]������ ���� ������ ���̴� 
		dp[i] = dp[i] % 9901;
		s[i] = s[i] % 9901;
	}
	
	cout << s[n] << '\n';
 	
}
