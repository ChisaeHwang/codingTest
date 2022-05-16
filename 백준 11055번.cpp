#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int arr[1001];
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, ans=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		dp[i] = arr[i]; // ���� ������ �ƴ� �� ���� �̹Ƿ� 
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) { // j < i �̴�  
				dp[i] = max(dp[i], dp[j] + arr[i]); // ���̿��� �� ������ �ٲ��� 
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	
	return 0;
}
