#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10001];

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int cnt = 0, sta = 0, end = 0, ret = 0;
	
	while (end <= n) {
		
		if (ret < m) {
			ret += arr[end]; // 이후에 들어올 값 + 
			end++;
		}
		
		if (ret >= m) {
			if (ret == m) cnt++;
			
			ret -= arr[sta]; // 이전에 있었던 값 - 
			sta++;
		}	
	}
	
	cout << cnt << '\n';
	
	
	return 0;
} 
