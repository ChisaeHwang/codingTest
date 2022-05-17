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
	
	for(int i=0; i<n; i++){ // 증가 
		d[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && d[i] < d[j]+1 ){ 
				d[i] = d[j] + 1;  // 증가하는 가장 긴 수 
			}
		}
	}
	
	for(int i=n-1; i>=0; i--){ // 감소 
		d2[i] = 1;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[i] && d2[i] < d2[j]+1 ){ 
				d2[i] = d2[j] + 1;  // 감소하는 가장 긴 수 
			}
		}
	}
	
	int ans = 0;
	
	for (int i=0; i<n; i++){
		if(ans < d[i] + d2[i] -1){ // 가장 긴 바이토닉 부분 수열 
			ans = d[i] + d2[i] -1; // d와 d2가 겹치기 때문에 -1를 함 
		}
	}
	
	cout << ans;
	
	
	return 0;
}
