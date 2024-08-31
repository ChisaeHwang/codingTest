#include <bits/stdc++.h>

using namespace std;

long long n, ret, cnt[100001], lo, hi, arr[100001];


int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	while (true) {
		if (hi == n) break;
		
		if (!cnt[arr[hi]]) {
		 	cnt[arr[hi]]++;
			hi++;
		} else {
			ret += (hi - lo);
			cnt[arr[lo]]--;
		 	lo++;
		}
	}
	
	ret += (long long )(hi - lo) * (hi - lo + 1) / 2;
	
	cout << ret << '\n'; 
	
	return 0;
} 
