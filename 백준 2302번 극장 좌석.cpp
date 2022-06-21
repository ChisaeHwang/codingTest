#include <iostream>
#include <vector>

using namespace std;

int vip[40];
int dp[41];
 
int main(){
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> vip[i];
	}
	
	dp[0] = dp[1] = 1; dp[2] = 2; // 초기값
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	if(m > 0){
		vector<int> q;
		
		q.push_back(vip[0] - 1); // 첫번째 VIP와 첫번째 좌석 사이 좌석의 개수 
		q.push_back(n - vip[m - 1]); // 마지막 VIP와 마지막 좌석 사이 좌석의 개수 
		
		for(int i=0; i<m-1; i++){
			q.push_back(vip[i+1] - vip[i] - 1); // vip 사이 좌석 개수 
		}
		
		int ans = 1;
		for(auto i : q){
			ans *= dp[i];
		}
		cout << ans;
	} else {
		cout << dp[n];
	}
	
	return 0;
} 
