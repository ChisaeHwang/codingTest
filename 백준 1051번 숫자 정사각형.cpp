#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51]; 
int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	
	int ret = 1;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 1; k < min(n, m); k++){ // 길이 1부터 그냥 n m 최고위치까지 완전탐색 
				if (i + k < n && j + k < m 
				&& arr[i + k][j] == arr[i][j] 
				&& arr[i + k][j + k] == arr[i][j] 
				&& arr[i][j + k] == arr[i][j]) {
					// 현재 위치에서 k 만큼 더해도 넘지 않는지, 현재 위치에서 우측, 하단, 대각선 순서대로 체크
					ret = max(ret, k + 1); // 현재까지 최고값이랑 k에서 거리를 더한 값 
					
				} 
			}
		}
	}
	
	ret = ret * ret;
	
	printf("%d", ret); 
	
	return 0;
}
