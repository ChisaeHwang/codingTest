#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, cnt[26]; // 알파벳 카운터 
string s, ret;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> s;
		cnt[s[0] - 'a']++; // String s의 [0]번째 = 첫 번째 문자의 값 
		// 'a' = 97 빼줌으로써 순서대로 cnt 가능 
	}
	
	for (int i = 0; i < 26; i++){
		if (cnt[i] >= 5) {
			ret += (i + 'a');
		}
	}
	
	if (ret.size()) // size가 0이면 어차피 false다 
	{
		cout << ret << '\n';
	} 
	else
	{
		cout << "PREDAJA" << '\n';
	}
	
	
	
	return 0;
} 
