#include <bits/stdc++.h>

using namespace std;

int cnt[201]; // 마이너스도 생각 
int n, m; 

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		cnt[100 + a]++;
	}
	
	cin >> m;
	
	cout << cnt[100 + m] << '\n';
	
	return 0;
}
