#include <bits/stdc++.h>

using namespace std;

int n, ret;
int arr[1001];
int dp1[1001];
int dp2[1001]; 


int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 
	
	for (int i = 0; i < n; i++) { // 증가 
		dp1[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[j] < arr[i]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	
	
	for(int i=n-1; i>=0; i--){ // 감소 
		dp2[i] = 1;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[i] && dp2[i] < dp2[j]+1 ){ 
				dp2[i] = dp2[j] + 1;  
			}
		}
	}


	for (int i = 0; i < n; i++){
		if(ret < dp1[i] + dp2[i] - 1){
			ret = dp1[i] + dp2[i] - 1;
		}
	}
	
	cout << ret;
	
	return 0;
}
