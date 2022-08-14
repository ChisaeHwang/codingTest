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
		
		// 수에 6이 적어도 3개이상 들어가는지 판별
		while (temp != 0)
		{
			if (temp % 1000 == 666) // 종말의 숫자라면
			{
				cnt++;
				break;
			}
			else temp /= 10; // 일의 자리수 삭제
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
