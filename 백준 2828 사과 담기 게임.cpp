#include <bits/stdc++.h>

using namespace std;

int n, m, k, ret, temp, l, r;

int main () {
	
	cin >> n >> m >> k;
	
	l = 1; // ���� ó��  �ٱ��� ���� ��ġ 
	
	for (int i = 0; i < k; i++){
		r = l + m - 1;
		cin >> temp; // ��� ��ġ 
		if (temp >= l && temp <= r) continue;  // �ٱ��� �ȿ� ������
		else {
			if (temp < l) {  // �ٱ��Ϸκ��� ���ʿ� 
				ret += (l - temp);
				l = temp;
			} else { // ������ 
				l += (temp - r);
				ret += (temp - r);
			}
		} 
	}
	
	cout << ret << '\n';
	
	return 0; 
} 
