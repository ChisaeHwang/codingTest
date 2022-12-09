#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

long long a, b, c;

long long go(long long a, long long b) {
	if (b == 1) return a % c;
	
	long long ret = go(a, b/2);
	ret = (ret * ret) % c;
	
	if (b % 2) { // Ȧ���� ��� 1�� ������ �ѹ� �� ���������, ��) 3 
		ret = (ret * a) % c;
	}
	
	return ret;
}

int main() {
	
	cin >> a >> b >> c;
	cout << go(a, b) << '\n';
	
	return 0;
}

