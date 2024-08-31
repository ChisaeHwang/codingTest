#include <bits/stdc++.h>

using namespace std;

int n, m, ret, lo, hi;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	
	cin >> m;
	
	sort(arr.begin(), arr.end()); // 오름차순 정렬 
	
	int sum = 0;
	
	lo = 0;
	hi = n - 1;

	while(true) {
		if (lo >= hi) break;
		
		if (arr[lo] + arr[hi] == m) ret++, hi--;
		else if	(arr[lo] + arr[hi] > m) hi--; // 크니깐 작게 
		else if (arr[lo] + arr[hi] < m) lo++; // 작으니깐 크게 
		
		
	}
	
	cout << ret << '\n';
	
	
	return 0;
}
