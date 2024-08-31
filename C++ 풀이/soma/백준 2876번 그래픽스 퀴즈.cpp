#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int dp[100001][5];
pair<int, int> arr[100001]; 

int main() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int first, second;
		cin >> first >> second;
		arr[i] = {first, second};
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 5; j++) {
			if(arr[i - 1].first == j || arr[i - 1].second == j) {
				dp[i][j] = dp[i - 1][j] + 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	
	int maxNum = 0; 
	int minGrade = INF;
		
	for(int i = 0; i <= n; i++) {
	    for(int j = 1; j <= 5; j++) {
	        if(dp[i][j] > maxNum) { // '>'를 사용하여 maxNum이 업데이트 될 때만 체크
	            maxNum = dp[i][j];
	            minGrade = j; // 최대값이 갱신되면 minGrade도 함께 업데이트
	        } else if (dp[i][j] == maxNum && j < minGrade) {
	            minGrade = j; // 같은 최대값을 가지며 더 작은 그레이드를 찾았으므로, minGrade를 업데이트
	        }
	    }
	}

	cout << maxNum << " " << minGrade << '\n';

	return 0; 
}
