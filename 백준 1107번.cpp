#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool broken[10];
int possible(int c) {
	if(c == 0){
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while(c > 0){
		if(broken[c % 10]) return 0; // 마지막 번호값이 0인 경우 
		len += 1;
		c /= 10;
	}
	
	return len;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; // 가고 싶은 채널, 부술 리모컨 버튼 수 
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int x; // 부수고 싶은거 선택 
		cin >> x;
		broken[x] = true;
	}
	
	int ans = n - 100;
	if(ans < 0){ // ans가 - 되면 예외처리 
		ans = -ans;
	}
	
	for(int i=0; i<=1000000; i++){
		int c = i; // 이동할 채널 
		int len = possible(c); // 숫자버튼 뭐 누를지 
		if(len > 0){  
			int press = c - n; // + 
			if(press < 0){
				press = -press; // -
			}
			if(ans > len + press){ // 숫자누른 횟수 + 플러스 마이너스 횟수 더하기 
				ans = len + press;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
