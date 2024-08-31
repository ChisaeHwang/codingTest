#include <bits/stdc++.h>

using namespace std;

int visited[10];
char sign[20];
int n;
vector<string> s;

bool oper(char x, char y, char op) {
	if (x > y && op == '>') return true;
	if (x < y && op == '<') return true;
	return false;
}

// dfs 느낌으로 푸는거임 이게 
void solve(int index, string str) {
	if (index == n-1) {
		s.push_back(str);
		return;
	}
	
	for (int i = 0; i < 9; i++){
		if (visited[i]) continue; // 이미 들어간 숫자 pass 
		if (index == 0 || oper(str[index - 1], i - '0', sign[index - 1])) {
			visited[i] = 1;
			solve(index + 1, str + to_string(i));
			visited[i] = 0;
		}
	}
	
	return;
}



int main() {

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> sign[i];	
	}	
	
	solve(0, "");
	sort(s.begin(), s.end());
	
	cout << s[s.size() - 1] << '\n' << s[0] << '\n';
	
	return 0;
} 
