#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000];
int arr[1000];
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i]; 
	}
	
	for(int i=n; i>=1; i--){
		dp[i] = 1;
		for(int j=i+1; j<=n; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j] + 1 ){ // 뒤에 있으면서 / 작은 수 중 가장 큰값을 하나씩 넣기 
				dp[i] = dp[j] + 1; // 조건에 맞는 경우 i에 j값을 넣고 1씩 길이가 추가 
			}
		}
	}
	
	int ans = dp[1];
	
	for (int i=2; i<=n; i++){
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	
	cout << ans;
	
    return 0;
}

  
