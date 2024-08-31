#include <bits/stdc++.h>

using namespace std;

int col[15];
int n, cnt;

bool check(int row) {
	for(int i = 0; i < row; i++) {
		if(col[row] == col[i] || abs(col[row] - col[i]) == abs(row - i)) {
			return false;
		}
	}
	
	return true;
}

void queen(int num) {
	if(num == n) {
		cnt++;
		return;
	}
	
	for(int i = 0; i < n; i++) {
		col[num] = i;
		
		if(check(num)) {
			queen(num + 1);
		}
	}
}

int main() {
	
	cin >> n;
	
	queen(0);
	
	cout << cnt << '\n';
	
	return 0;
}
