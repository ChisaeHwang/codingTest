#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, cnt[26]; // ���ĺ� ī���� 
string s, ret;

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> s;
		cnt[s[0] - 'a']++; // String s�� [0]��° = ù ��° ������ �� 
		// 'a' = 97 �������ν� ������� cnt ���� 
	}
	
	for (int i = 0; i < 26; i++){
		if (cnt[i] >= 5) {
			ret += (i + 'a');
		}
	}
	
	if (ret.size()) // size�� 0�̸� ������ false�� 
	{
		cout << ret << '\n';
	} 
	else
	{
		cout << "PREDAJA" << '\n';
	}
	
	
	
	return 0;
} 
