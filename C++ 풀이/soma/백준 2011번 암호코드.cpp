#include <bits/stdc++.h>

#define mod 1000000

using namespace std;

int dp[5001];
int n, k, ret; 
string s; 

int main() {
	
	cin >> s;
	
	int len = s.size();
	
	if (s[0] == '0') {
		cout << 0 << '\n';
		return 0;
	}
	
	dp[0] = 1, dp[1] = 1;
	
	for (int i = 2; i <= len; i++) {
        if(s[i-1] > '0')  {
			dp[i] = dp[i-1] % mod; //s�� ���簪(i-1)�� 0�� �ƴ� ��
		}
        
        int n = (s[i-2]-'0') * 10 + s[i-1] - '0'; //s[i-2 ~ i-1]�� 10~26�� ��
        
		if(10 <= n && 26 >= n){
            dp[i] = (dp[i] + dp[i-2]) % mod;
        }
	}
	
	cout << dp[len] << '\n';



	return 0;
} 
