#include <bits/stdc++.h>

using namespace std;

string n, m, ret;

int main() {
	
	cin >> n >> m;
	
	
	// stack을 대신 사용해도 될듯 // 비슷한 문제 짝짓기 문제 
	for (char a : n) {
		ret += a;
		if (ret.size() >= m.size() && ret.substr(ret.size() - m.size(), m.size()) == m) {
			ret.erase(ret.end() - m.size(), ret.end()); // ret 마지막 크기 - m 크기 
		}
	}
	
	// erase(위치, 크기) 
	
	if(!ret.size()) cout << "FRULA" << '\n';
	else cout << ret << '\n';
	
	return 0;
} 
