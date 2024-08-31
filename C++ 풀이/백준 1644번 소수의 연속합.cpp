#include <bits/stdc++.h>

using namespace std;

// 투포인터 문제 감 익히기 용도
// 제대로 익혀야 함 
int n, ret, arr[2000001], lo, hi, sum, p;
bool check[4000001];

int main() {
	
	cin >> n;
	for (int i = 2; i <= n; i++){
		if(check[i]) continue;
		for (int j = 2*i; j <= n; j += i) { // 소수가 아닌 값만 나옴 
			check[j] = 1; // 소수가 아닌 것들 true 
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			arr[p++] = i; // 소수 체크 
		}
	}	
	
	while(true) {
		if (sum >= n) sum -= arr[lo++];
		else if (hi == p) break; // p의 위치 : 최종 소수의 위치 
		else if (sum < n) sum += arr[hi++];
		if (sum == n) ret++;
		// 투포인터로 움직이면서 sum의 값이 n과 같을때마다 count 
	}
	
	cout << ret << '\n';
	
	
	return 0;
} 
