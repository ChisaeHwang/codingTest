#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) { // ������ �������ؼ� n���� �ּ��� ������ 2��ŭ �۾ƾ��� 
		if (n % i == 0) return 0;
	}
	
	return 1; 
}

int main() {
	
	cin >> n >> m;
	
	for (int i = n; i <= m; i++) {
		if (check(i)) {
			v.push_back(i);
		}
	}
	
	for (int r : v) {
		cout << r << '\n';
	}
	
	
	return 0;
}
