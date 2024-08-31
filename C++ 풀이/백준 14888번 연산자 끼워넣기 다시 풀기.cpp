#include <bits/stdc++.h>

using namespace std;
#define plus aaa

int arr[101]; 
int pls, minu, multi, divi, retMax = -987654321, retMin = 987654321;
int n;

void solve(int idx, int cnt, int pl, int mi, int mul, int div) {
	
	if (idx == n - 1) {
		retMax = max(retMax, cnt);
		retMin = min(retMin, cnt);
		return;
	}
	
	if (pl) solve (idx + 1, cnt + arr[idx + 1], pl - 1, mi, mul, div);
	if (mi) solve (idx + 1, cnt - arr[idx + 1], pl, mi - 1, mul, div);
	if (mul) solve (idx + 1, cnt * arr[idx + 1], pl, mi, mul - 1, div);		
	if (div) solve (idx + 1, cnt / arr[idx + 1], pl, mi, mul, div - 1);	
	
	return;
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cin >> pls >> minu >> multi >> divi;
	
	solve(0, arr[0], pls, minu, multi, divi);
	
	cout << retMax << '\n';
	cout << retMin << '\n';
	
	
	return 0;
} 
