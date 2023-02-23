#include <iostream>
#include <string>

using namespace std;

string s;
int num[10];
int ret;

// 굳이 9까지 계산할 필요가 없었다
 

int main() {
	
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		num[s[i] - '0']++;
	}
	
	num[6] = (num[6] + num[9] + 1) / 2;
	
	for (int i = 0; i < 9; i++) {	
		ret = max(ret, num[i]);	
	}
	
	cout << ret << '\n';
	
	return 0;
}


