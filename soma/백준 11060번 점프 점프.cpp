#include <bits/stdc++.h>

using namespace std;

const int INF = 1001; 
int dp[1001];
int arr[1001];
int n;

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  fill(dp, dp + 1001, INF);

  dp[1] = 0;

  for (int i = 1; i <= n; i++) {
    int jump = arr[i];
    for (int j = 0; j <= jump; j++) {
      if(i + j <= n) {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
  }

  if (dp[n] == INF) cout << -1 << '\n'; 
  else cout << dp[n] << '\n';


  return 0;
}
