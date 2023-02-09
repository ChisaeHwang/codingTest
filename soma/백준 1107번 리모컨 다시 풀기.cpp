#include <bits/stdc++.h>

using namespace std;

int arr[11];
int n, m, a; 

int ok(int c) {
	if (c == 0) {
		return arr[c] ? 0 : 1;
	}
	
	int len = 0;
	
	while (c > 0) {
		if(arr[c % 10]) return 0; // 마지막 번호값이 0인 경우
		len += 1;
		c /= 10;
	}
	
	return len;
}


int main() {

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a;
		arr[a] = 1;	
	}
	
	int ret = n - 100;
	
	if (ret < 0) {
		ret = -ret;
	}
	
	for (int i = 0; i <= 10; i++) {
		int c = i; // 이동 채널 
		int len = ok(c); // len \
		
		if (len > 0) {
			int press = c - n;
			
			if (press < 0) {
				press = -press;
			}
			
			ret = min(ret, len + press);
		} 
	}
	
	cout << ret << '\n';
	
	
	
	return 0;
}
