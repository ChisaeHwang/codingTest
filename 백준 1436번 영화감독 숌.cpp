#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

int main() {
	
	int n, ans, cnt;
	cin >> n;
	
	ans = 0;
	cnt = 0;
	
	while(true) {
		if(cnt == n){
			break;
		}
		
		ans++;
		int temp = ans;
		
		// ���� 6�� ��� 3���̻� ������ �Ǻ�
		while (temp != 0)
		{
			if (temp % 1000 == 666) // ������ ���ڶ��
			{
				cnt++;
				break;
			}
			else temp /= 10; // ���� �ڸ��� ����
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
