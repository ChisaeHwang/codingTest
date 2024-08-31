#include <bits/stdc++.h>

using namespace std;

int n; 
string ans = "";

bool check(string s, int len) {
	for (int i = 1; i <= len / 2; i++) {
		string prev = s.substr(len - 2 * i, i);
		string cur = s.substr(len - i, i);
		if (prev == cur) return false;
	}
	return true;
}

void dfs(string s, int depth) {
	if (!ans.empty()) return;
	
	if (depth == n) {
		ans = s;
		return;
	}
	
	for (int i = 1; i <= 3; i++) {
		string temp = s + to_string(i);
		if(check(temp, depth + 1)) {
			dfs(temp, depth + 1);
		}
	}
}

int main() {
	
	cin >> n;
	
	dfs("1", 1);
	
	cout << ans << '\n';
	
	return 0;
}
