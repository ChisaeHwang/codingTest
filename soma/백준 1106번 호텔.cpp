#include <bits/stdc++.h>

using namespace std;

int c, n;
int dp[100001];
vector<pair<int, int>> v;

int main() {

	cin >> c >> n;
	
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}	

	for (int i = 0; i < v.size(); i++)
	{
			for (int k = 1; k <= c; k++)
			{
				if(k - v[i].first >= 0) // 이걸 체크 안하면 dp에 -인자들이 들어감 
				dp[k] = max(dp[k], dp[k - v[i].first] + v[i].second);
				// 각 dp에서 들어갈 수 있는 최댓값 넣기 
			}
		
	}
	
	for (int i = 1; i <= 100001; i++)
	{
		if (dp[i] >= c)
		{
			cout << i;
			break;
		}
	}
	
	
	
	return 0;
}
