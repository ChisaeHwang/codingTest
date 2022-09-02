#include <iostream>
#include <algorithm>

using namespace std;

// 랜선의 길이가 INT_MAX인 2,147,483,647까지 가능
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
		// mid 연산
		mid = (low + high) / 2;
        
		// 몫의 합을 저장하는 변수
		unsigned int now = 0; 
        
		for (int i = 0; i < K; i++)
		{
			//mid로 나눈 몫을 저장
			now += list[i] / mid;
		}

		if (now >= N)
		{
			// 현재 mid로 나눈 값이 N보다 크거나 같다면,
			// left를 움직여 길이가 더 긴 경우는 가능한지 검사
			low = mid + 1;
            
			// N개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			ans = max(ans, mid);
		}
		else
		{
			// 현재 mid로 나눈 값이 N보다 작다면,
			// right 움직여 길이가 더 짧은 경우는 가능한지 검사
			high = mid - 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0; 
}
