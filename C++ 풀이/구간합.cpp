#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int a[100001], b, c, psum[100001], n, m;

int main(){

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 1���� ä���
		psum[i] = a[i] + psum[i - 1]; // �������� �� �ֱ� 
	}
	
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		int sum = 0;
		sum = psum[c] - psum[b - 1]; // C���� �����հ� B - 1 R������ �������� ���ָ� �� 
		cout << sum << '\n';
	}
	

	return 0;	
}
