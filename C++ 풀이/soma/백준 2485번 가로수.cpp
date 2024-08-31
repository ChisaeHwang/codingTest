#include <bits/stdc++.h>

using namespace std;

int n;
int tree[100001];
int sum[100001];
int cnt;

int gcd(int a, int b) { // a�� b�� ���� �������� R�̶�� �� �� 
    if (b == 0) return a; // b�� R�� �ִ������� a�� b�� �ִ������� ���� 
    return gcd(b, a % b ); // �׷��Ƿ� R�� ���� �� ������ �ݺ� 
}				// R �� 

int main() {
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}
	
	for (int i = 2; i <= n; i++) {
		sum[i - 1] = tree[i] - tree[i - 1];
	} // Ʈ������ ���� ���� ���� 
	
	int temp = gcd(sum[2], sum[1]);
	
	for (int i = 3; i < n; i++) {
		temp = gcd(sum[i], temp);
	} // ������ �ִ� ����� ã�� 
	
	for (int i = 1; i < n; i++) {
		int ret = sum[i];
		while(ret > temp) {
			ret -= temp;
			cnt++;
		}
	} // �ִ� ������� ���缭 ���� �ɱ� 
	
	cout << cnt << '\n';

	return 0; 
}
