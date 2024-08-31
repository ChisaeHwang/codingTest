#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i]; 
	}
	
	vector<int> d(n);
	vector<int> d2(n);
	
	for(int i=0; i<n; i++){ // ���� 
		d[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && d[i] < d[j]+1 ){ 
				d[i] = d[j] + 1;  // �����ϴ� ���� �� �� 
			}
		}
	}
	
	for(int i=n-1; i>=0; i--){ // ���� 
		d2[i] = 1;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[i] && d2[i] < d2[j]+1 ){ 
				d2[i] = d2[j] + 1;  // �����ϴ� ���� �� �� 
			}
		}
	}
	
	int ans = 0;
	
	for (int i=0; i<n; i++){
		if(ans < d[i] + d2[i] -1){ // ���� �� ������� �κ� ���� 
			ans = d[i] + d2[i] -1; // d�� d2�� ��ġ�� ������ -1�� �� 
		}
	}
	
	cout << ans;
	
	
	return 0;
}
