#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[9];
	int sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i]; // 9명 키의 합 
	}

	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) { // 7명의 합 
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << '\n';
				}
				return 0; // 가능한 정답이 여러가지일 경우 하나만 출력해야한다. 
			}
		}
	}
	return 0;
}
