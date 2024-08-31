#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001]; 

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int cnt = 987654321;
	int start = 0, end = 0, ret = 0;
	
	while (end <= n) {
		
		if (ret < m) {
			ret += arr[end];
			end++;
		}
		
		if (ret >= m) {
			cnt = min(cnt, (end - start));
			
			ret -= arr[start];
			start++;
		}
	}
	
	if (cnt == 987654321) {
		cout << 0 << '\n';
	} else {
		cout << cnt << '\n';	
	}
 	 
	
	return 0;
}
