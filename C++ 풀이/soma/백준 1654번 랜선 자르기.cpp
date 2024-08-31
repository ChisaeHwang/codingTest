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
			//mid로 나눈 몫을 저장
			now += arr[i] / mid;
		}

		if (now >= m)
		{
			// 현재 mid로 나눈 값이 N보다 크거나 같다면,
			// left를 움직여 길이가 더 긴 경우는 가능한지 검사
			left = mid + 1;
            
			// N개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			ans = max(ans, mid);
		}
		else
		{
			// 현재 mid로 나눈 값이 N보다 작다면,
			// right 움직여 길이가 더 짧은 경우는 가능한지 검사
			right = mid - 1;
		}
		
		cout << mid << '\n';
		
	}
	
	cout << ans << '\n';
	
	return 0;
}
