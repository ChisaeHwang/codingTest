#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int E, S, M;
	cin >> E >> S >> M;
	int e=1, s=1, m=1;
	
	for(int i=1;; i++){
		if(e == E && s == S && m == M){ // 입력한 값과 동일하면 해당 년수 출력 후 break 
			cout << i << '\n';
			break;
		}
		
		e += 1;
		s += 1;
		m += 1;
		
		if(e == 16) e = 1; // 나머지 연산으로도 풀 수 있음 
		if(s == 29)	s = 1;
		if(m == 20) m = 1;
	}
	
	return 0;
}
