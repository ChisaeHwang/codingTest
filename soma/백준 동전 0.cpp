#include <bits/stdc++.h>

using namespace std;

int n, k, ret;
int arr[11];

int main() {
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = n - 1; i >= 0; i--) { // 큰거부터 나눠보기 
		ret += k / arr[i]; // 4200 / 1000 = 4 / 200 / 100 = 2 
		k = k % arr[i]; // 4200 % 1000 = 200 / 200 / 100 = 0
	}
	
	cout << ret << '\n';
	
	
	
	return 0;
}
