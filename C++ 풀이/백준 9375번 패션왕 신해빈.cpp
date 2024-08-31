#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;


int t, n;
string a, b;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		map<string, int> map;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			map[b]++;
		}
		long long ret = 1; // 경우의수는 많기 때문에 long long이 안전함 
		for (auto c : map) {
			ret *= ((long long)c.second + 1);
		}
		ret--;
		
		cout << ret << '\n';
		
	}
	
	return 0;
} 
