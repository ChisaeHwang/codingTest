#include <iostream>
#include <algorithm>

using namespace std;

// ������ ���̰� INT_MAX�� 2,147,483,647���� ����
unsigned int ans;
unsigned int N,K;
unsigned int list[10000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> K >> N;
    
	unsigned int maxNum = 0;
    
	for (int i = 0; i < K; i++)
	{
		cin >> list[i];
		maxNum = max(maxNum, list[i]);
	}

	unsigned int low = 1, high = maxNum, mid;
	
	while (low <= high)
	{
		// mid ����
		mid = (low + high) / 2;
        
		// ���� ���� �����ϴ� ����
		unsigned int now = 0; 
        
		for (int i = 0; i < K; i++)
		{
			//mid�� ���� ���� ����
			now += list[i] / mid;
		}

		if (now >= N)
		{
			// ���� mid�� ���� ���� N���� ũ�ų� ���ٸ�,
			// left�� ������ ���̰� �� �� ���� �������� �˻�
			low = mid + 1;
            
			// N���� ���� �� ���� ��, ���� �� ū ������ ��� ����
			ans = max(ans, mid);
		}
		else
		{
			// ���� mid�� ���� ���� N���� �۴ٸ�,
			// right ������ ���̰� �� ª�� ���� �������� �˻�
			high = mid - 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0; 
}
