#include <bits/stdc++.h>

using namespace std;

string n, m, ret;

int main() {
	
	cin >> n >> m;
	
	
	// stack�� ��� ����ص� �ɵ� // ����� ���� ¦���� ���� 
	for (char a : n) {
		ret += a;
		if (ret.size() >= m.size() && ret.substr(ret.size() - m.size(), m.size()) == m) {
			ret.erase(ret.end() - m.size(), ret.end()); // ret ������ ũ�� - m ũ�� 
		}
	}
	
	// erase(��ġ, ũ��) 
	
	if(!ret.size()) cout << "FRULA" << '\n';
	else cout << ret << '\n';
	
	return 0;
} 
