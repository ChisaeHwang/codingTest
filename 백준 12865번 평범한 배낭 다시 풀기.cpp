#include <bits/stdc++.h>

using namespace std;

int n, k, w, v;
int dp[100001]; // 무게당 최댓값 

int main() {
	
	
	scanf("%d %d", &n, &k);
	
	while(n--) {
		scanf("%d %d", &w, &v);
		for (int j = k; k >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v); 
		}
	}
	
	printf("%d\n", dp[k]);
	
	return 0;
}
