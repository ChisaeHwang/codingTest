#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int s[100001]; // 시작 시간 
int e[100001]; // 끝나는 시간 
int p[100001]; // 회의실 인원 

int main() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int to, from, cost;
		cin >> to >> from >> cost;
		s[i] = to;
		e[i] = from;
		p[i] = cost;
	}
	
	dp[0] = p[0];
	
	for(int i = 1; i <= n; i++) {
		if(e[i - 1] > s[i]) { // 시작 시간이 겹치는 경우 
			dp[i] = max(dp[i - 1], dp[i - 2] + p[i]);
		} else {
			dp[i] = dp[i - 1] + p[i];
		}
	}
	
	cout << dp[n] << '\n'; 
	
	return 0; 
}
