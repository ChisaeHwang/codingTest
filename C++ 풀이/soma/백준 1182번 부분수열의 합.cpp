#include <bits/stdc++.h>

using namespace std;

int n, s, cnt;
int arr[1000000]; 

void go(int idx, int ret) {
	
	if (idx == n) {
		if (ret == s) cnt++;
		return;
	}
	
	go(idx + 1, ret);
	go(idx + 1, ret + arr[idx]);
	
}

int main() {
	
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	go(0, 0);
	
	if (s == 0) cnt--; // s�� 0�̸� ��� ������ �� �ϴ� ������ 0�� ���־���� 
	
	cout << cnt << '\n';
	
	
	return 0;
}
