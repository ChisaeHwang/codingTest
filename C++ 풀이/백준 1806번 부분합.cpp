#include <iostream>
#include <algorithm>

#define MOD 1e9

using namespace std;

int arr[100001];

int main() {
	
	int n, s;
	int length = MOD;
	int left = 0;
	int right = 0;
	int sum = 0;
	
	cin >> n >> s;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	sum = arr[0];
	
		while (left <= right && right < n) {
		if (sum < s){
			sum += arr[++right]; // right ������ �̵� 
		}
		else if(sum == s) {
			length = min(length, (right - left + 1)); // �κ��� �ּ� ���� ���� 
			sum += arr[++right]; // right ������ �̵� 
		}
		else if (sum > s) {
			length = min(length, (right - left + 1));
			sum -= arr[left];
			left++; // left ������ �̵� 
		}
	}
	
	if(length == MOD){
		cout << 0 << '\n';
	} else {
		cout << length << '\n';
	}
	
	
	return 0;
}
