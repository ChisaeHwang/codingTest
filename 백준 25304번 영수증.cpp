#include <bits/stdc++.h>

using namespace std;

int n, ret, sum;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> ret;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		int a, aSum;
		cin >> a >> aSum;
		sum += aSum * a;
	}
	
	if (ret == sum) cout << "Yes" << '\n';
	else cout << "No" << '\n';
		
	
	return 0;
} 
