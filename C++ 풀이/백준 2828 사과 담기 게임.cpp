#include <bits/stdc++.h>

using namespace std;

int n, m, k, ret, temp, l, r;

int main () {
	
	cin >> n >> m >> k;
	
	l = 1; // 가장 처음  바구니 왼쪽 위치 
	
	for (int i = 0; i < k; i++){
		r = l + m - 1;
		cin >> temp; // 사과 위치 
		if (temp >= l && temp <= r) continue;  // 바구니 안에 있으면
		else {
			if (temp < l) {  // 바구니로부터 왼쪽에 
				ret += (l - temp);
				l = temp;
			} else { // 오른쪽 
				l += (temp - r);
				ret += (temp - r);
			}
		} 
	}
	
	cout << ret << '\n';
	
	return 0; 
} 
