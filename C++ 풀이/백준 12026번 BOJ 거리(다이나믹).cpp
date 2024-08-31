#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char arr[1001];
int dp[1001];

int main(){
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	fill(dp, dp + 1001, 1e9);
	
	dp[1] = 0;
	
	for(int i=1; i<n; i++){
		if(arr[i] == 'B')
		{
			for(int j=i+1; j<=n; j++)
			{
				if(arr[j] == 'O')
				{
					dp[j] = min(dp[j], (j-i)*(j-i) + dp[i]);
				}
			}
		} 
		else if (arr[i] == 'O')
		{
			for(int j=i+1; j<=n; j++)
			{
				if(arr[j] == 'J')
				{
					dp[j] = min(dp[j], (j-i)*(j-i) + dp[i]);
				}
			}
		} 
		else 
		{
			for(int j=i+1; j<=n; j++)
			{
				if(arr[j] == 'B')
				{
					dp[j] = min(dp[j], (j-i)*(j-i) + dp[i]);
				}
			}
		}
	}
	
	if(dp[n] == 1e9)
	{
		cout << -1 <<'\n';
	}
	else
	{
		cout << dp[n] <<'\n';
	}
	
	return 0;
} 
