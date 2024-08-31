#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int s[100001];

int main(){
	
	int N;
	cin >> N;
	dp[0] = s[0] = 1; // dp[0]에 채우는 방법도 하나 있다 
	dp[1] = 2; // dp[1]에는 O X / X O 라는 선택지가 있다 
	s[1] = dp[0] + d[1]; // s는 dp의 값을 누적하는 것 이기에 dp[0] + dp[1] 을 더해주면 됨 
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + 2*s[i-2];
		s[i] = s[i-1] + dp[i]; // s는 d[0]부터 d[i]까지의 수를 누적한 것이다 
		dp[i] = dp[i] % 9901;
		s[i] = s[i] % 9901;
	}
	
	cout << s[n] << '\n';
 	
}
