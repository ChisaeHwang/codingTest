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
			ret += arr[end]; // ���Ŀ� ���� �� + 
			end++;
		}
		
		if (ret >= m) {
			if (ret == m) cnt++;
			
			ret -= arr[sta]; // ������ �־��� �� - 
			sta++;
		}	
	}
	
	cout << cnt << '\n';
	
	
	return 0;
} 
