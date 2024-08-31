#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n, ans = -1001;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		dp[i] =  arr[i]; // �������� �ʴ� ��� 
		if(dp[i] < dp[i-1] + arr[i]){ // �����ϴ� ���
			dp[i] = max(dp[i-1] + arr[i], arr[i]);
		}	
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
    return 0;
}

  
