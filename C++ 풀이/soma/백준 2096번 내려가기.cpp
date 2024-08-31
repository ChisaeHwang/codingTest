#include <bits/stdc++.h>

using namespace std;

int n, k, ret;
int dp[10001][100001]; // 배낭에 넣을 물건 번호, 현재 배낭의 무게 
int arr[100001][100001];

int go(int y, int x) {
	
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];	
		}
	} 


	memset(dp, -1, sizeof(dp));
	
	
	
	
	return 0;
}
