#include <bits/stdc++.h>

using namespace std;

unsigned int ans;
unsigned int n, m;
unsigned int arr[10000];

int main() {
	
	cin >> n >> m;
	
	unsigned int maxNum = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxNum = max(maxNum, arr[i]);
	}
	
	unsigned int left = 1, right = maxNum, mid;
	
	while (left <= right) {
		
		mid = (right + left) / 2;
		
		unsigned int now = 0;
		
		for (int i = 0; i < n; i++)
		{
			//mid�� ���� ���� ����
			now += arr[i] / mid;
		}

		if (now >= m)
		{
			// ���� mid�� ���� ���� N���� ũ�ų� ���ٸ�,
			// left�� ������ ���̰� �� �� ���� �������� �˻�
			left = mid + 1;
            
			// N���� ���� �� ���� ��, ���� �� ū ������ ��� ����
			ans = max(ans, mid);
		}
		else
		{
			// ���� mid�� ���� ���� N���� �۴ٸ�,
			// right ������ ���̰� �� ª�� ���� �������� �˻�
			right = mid - 1;
		}
		
		cout << mid << '\n';
		
	}
	
	cout << ans << '\n';
	
	return 0;
}
