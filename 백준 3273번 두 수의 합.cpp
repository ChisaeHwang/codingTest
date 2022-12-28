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
	
	sort(arr.begin(), arr.end()); // �������� ���� 
	
	int sum = 0;
	
	lo = 0;
	hi = n - 1;

	while(true) {
		if (lo >= hi) break;
		
		if (arr[lo] + arr[hi] == m) ret++, hi--;
		else if	(arr[lo] + arr[hi] > m) hi--; // ũ�ϱ� �۰� 
		else if (arr[lo] + arr[hi] < m) lo++; // �����ϱ� ũ�� 
		
		
	}
	
	cout << ret << '\n';
	
	
	return 0;
}
