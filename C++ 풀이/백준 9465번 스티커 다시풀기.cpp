#include <bits/stdc++.h>

using namespace std;

int arr[5][100001]; // dp[행][점수] 
int dp[100001][5]; // dp[최댓값][가만히 있기, 떼기, 안 떼기] 
int t, n, ret;

int go(int cnt, int row) {
	if (cnt == n) return 0; // 기본 케이스
	if (dp[cnt][row] != -1) return dp[cnt][row]; // 이미 방문한 경우 
	
	int ret = go(cnt + 1, 0); // 스티커 안 떼는 경우 
	if(row != 1) ret = max(ret, go(cnt + 1, 1) + arr[0][cnt]); // 1번행 뗄 경우
	if(row != 2) ret = max(ret, go(cnt + 1, 2) + arr[1][cnt]); // 2번행 뗄 경ㅇ 
	dp[cnt][row] = ret; //해당 배열에서 얻을 수 있는 최댓값 
	
	return ret;
}

int main() {
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		
		cout << go(0, 0) << '\n';
		  
	}
	
	
	
	
	return 0; 
} 
