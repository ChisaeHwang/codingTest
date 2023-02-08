#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int sum[1001];
int n, cnt;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		sum[i] = arr[i] + sum[i - 1];
		cnt += sum[i];
	}
	
	cout << cnt << '\n';
	
	
	
	return 0;
}
