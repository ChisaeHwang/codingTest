#include <bits/stdc++.h>

using namespace std;

// �������� ���� �� ������ �뵵
// ����� ������ �� 
int n, ret, arr[2000001], lo, hi, sum, p;
bool check[4000001];

int main() {
	
	cin >> n;
	for (int i = 2; i <= n; i++){
		if(check[i]) continue;
		for (int j = 2*i; j <= n; j += i) { // �Ҽ��� �ƴ� ���� ���� 
			check[j] = 1; // �Ҽ��� �ƴ� �͵� true 
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			arr[p++] = i; // �Ҽ� üũ 
		}
	}	
	
	while(true) {
		if (sum >= n) sum -= arr[lo++];
		else if (hi == p) break; // p�� ��ġ : ���� �Ҽ��� ��ġ 
		else if (sum < n) sum += arr[hi++];
		if (sum == n) ret++;
		// �������ͷ� �����̸鼭 sum�� ���� n�� ���������� count 
	}
	
	cout << ret << '\n';
	
	
	return 0;
} 
