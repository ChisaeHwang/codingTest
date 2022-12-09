#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

long long a, b, c;

long long go(long long a, long long b) {
	if (b == 1) return a % c;
	
	long long ret = go(a, b/2);
	ret = (ret * ret) % c;
	
	if (b % 2) { // 홀수일 경우 1이 나오고 한번 더 곱해줘야함, 예) 3 
		ret = (ret * a) % c;
	}
	
	return ret;
}

int main() {
	
	cin >> a >> b >> c;
	cout << go(a, b) << '\n';
	
	return 0;
}

