#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1000001]; 

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	long long c;
	
	cin >> n >> c;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	long long low = 0, high = arr[n - 1];
	
	while(low <= high) 
	{
		long long cnt = 0;
		int mid = (low + high) / 2;
		
		for (int i = 0; i < n; i++){
			if (arr[i] > mid){
				cnt += (arr[i] - mid);
			}
		}
		
		if (cnt >= c) // ������ ����� ��� 
		{
			low = mid + 1;
		}
		else  // ������ ���� ��� 
		{
			high = mid - 1;
		}
	}
	
	cout << high << '\n';
	
	return 0;
}
