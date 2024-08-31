#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

typedef long long LL;
int n, m;
string s;
map<string, int> map1;
map<int, string> map2;
string arr[100001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++){
		cin >> s;
		map1[s] = i + 1;
		map2[i + 1] = s;
		arr[i + 1] = s; // 배열 같은 경우엔 
	}
	
	for (int i = 0; i < m; i++){
		cin >> s;
		if (atoi(s.c_str()) == 0) { // atoi가 0이면 문자열임 
			cout << map1[s] << '\n';
		} else {
			cout << map2[atoi(s.c_str())] << '\n';
		}
	}


	return 0;	
}
