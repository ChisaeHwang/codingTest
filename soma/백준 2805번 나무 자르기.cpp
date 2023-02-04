#include <bits/stdc++.h>

using namespace std;

long long arr[1000001]; 
int n;
long long c;

int main() {
	
	cin >> n >> c;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	
	sort(arr, arr + n);
	
	long long low = 0, high = arr[n - 1];
	
	while (low <= high) {
		long long cnt = 0;
		
		int mid = (low + high) / 2;
		
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				cnt += (arr[i] - mid);
			}	
		}
		
		if (cnt >= c) { // ������ ���� ��� low�� ��ܿ� Ǯ�� 
			low = mid + 1;
		} else { // ������ ���� ��� high�� ��ܿ� Ǯ�� 
			high = mid - 1;
		}	
 	}
 	
 	cout << high << '\n';
	
	
	
	
	return 0;
}
