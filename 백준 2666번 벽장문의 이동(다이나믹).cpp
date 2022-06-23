#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t;
int check[21];
int dp[21][21][21]; // 벽장 순서, oepn 두곳 

int go(int idx, int first, int second){
	if(idx > t) return 0;
	int result = dp[idx][first][second];
	if(result != -1) return result;
	
	int target = check[idx];
	dp[idx][first][second] = min(abs(first-target) + go(idx+1, target, second), abs(second-target) + go(idx+1, first, target));
	
	return dp[idx][first][second]; 
	
}

int main(){
	
	memset(dp, -1, sizeof(dp));

	cin >> n;
	
	int first, second;
	cin >> first >> second;
	
	cin >> t;
	for(int i=1; i<=t; i++){
		cin >> check[i];
	}
	
	cout << go(1, first, second) << '\n';
	
	return 0;
}
