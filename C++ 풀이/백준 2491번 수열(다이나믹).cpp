#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int check[100001];

int main() {

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> dp[i];
	}
	
	int result = 0;
	check[0] = 1;
	for(int i=1; i<n; i++){
		if(dp[i-1]<=dp[i]){
			check[i] = check[i-1]+1;
		} else {
			check[i] = 1;
		}
	}
	
	for(int i=0; i<n; i++){
		result = max(result, check[i]);
	}
	
	for(int i=1; i<n; i++){
		if(dp[i-1]>=dp[i]){
			check[i] = check[i-1]+1;
		} else {
			check[i] = 1;
		}
	}
	
	for(int i=0; i<n; i++){
		result = max(result, check[i]);
	}
	
	cout << result << '\n';
	
	
	
	return 0;
}
