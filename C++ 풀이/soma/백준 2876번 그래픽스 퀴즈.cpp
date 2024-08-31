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
	        if(dp[i][j] > maxNum) { // '>'�� ����Ͽ� maxNum�� ������Ʈ �� ���� üũ
	            maxNum = dp[i][j];
	            minGrade = j; // �ִ밪�� ���ŵǸ� minGrade�� �Բ� ������Ʈ
	        } else if (dp[i][j] == maxNum && j < minGrade) {
	            minGrade = j; // ���� �ִ밪�� ������ �� ���� �׷��̵带 ã�����Ƿ�, minGrade�� ������Ʈ
	        }
	    }
	}

	cout << maxNum << " " << minGrade << '\n';

	return 0; 
}
