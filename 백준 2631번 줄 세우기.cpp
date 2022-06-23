#include <iostream>
using namespace std;

int dp[201];
int arr[201];

int main(){
	
	int n;
	cin >> n;
	
	int max = 0;
	
	for(int i=0; i<n; i++){
		dp[i] = 1;
		cin >> arr[i];
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		
		if(max < dp[i]){
			max = dp[i];
		}
	}
	
	cout << n - max << '\n';
	
	return 0;
}
