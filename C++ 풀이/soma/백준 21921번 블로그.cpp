#include <bits/stdc++.h>

using namespace std;

int n, x;
int arr[250001];
int sum;
int cnt = 1;

int main() {
	
	cin >> n >> x;
	
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
		sum += arr[i];	
	}
	
	int ans = sum;
	
	for (int i = x; i < n; i++) {
		cin >> arr[i];
		sum += arr[i] - arr[i - x]; // 1 ~ n일차까지 누적합
		
		if (sum >= ans) {
			if (sum == ans) {
				cnt++;
			} else {
				ans = sum;
				cnt = 1;
			}
		}
	}
	
	if (ans == 0) {
		cout << "SAD" << '\n';
	} else {
		cout << ans << '\n' << cnt << '\n';
	}	
	
	return 0;
}
