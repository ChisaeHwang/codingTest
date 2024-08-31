#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	
	cin >> n;
	
	vector<bool> v(n + 1);
	
	// 에라토스테네스의 체 
	for (int i = 2; i * i <= n; i++) {
		if (v[i]) continue;
		for (int j = i + i; j <= n; j += i) { // 짝수들 다 체크 
			v[j] = 1; 
		}	
	}
	
	vector<int> arr;
	
	for (int i = 2; i <= n; i++) {
		if (v[i]) continue;
		arr.push_back(i);
	}
	
	int start = 0, end = 0;
	int ret = 0, cnt = 0;
	
	while (true) {
		if (ret < n) {
			if (end >= arr.size()) break;
			ret += arr[end];
			end++;
		} 
		
		if (ret >= n) {
			if (ret == n) cnt++;
			
			ret -= arr[start];
			start++;
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}
