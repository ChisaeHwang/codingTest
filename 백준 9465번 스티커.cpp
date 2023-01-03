#include <bits/stdc++.h>

using namespace std;

int t, n;
int arr[2][100001];
int dp[100001][3];

int go(int cnt, int row) {
	if (cnt == n) return 0; // �⺻ ���̽�
	if (dp[cnt][row] != -1) return dp[cnt][row]; // �̹� �湮�� ��� 
	
	int ret = go(cnt + 1, 0); // ��ƼĿ �� ���� ��� 
	if(row != 1) ret = max(ret, go(cnt + 1, 1) + arr[0][cnt]); // 1���� �� ���
	if(row != 2) ret = max(ret, go(cnt + 1, 2) + arr[1][cnt]); // 2���� �� �椷 
	dp[cnt][row] = ret; //�ش� �迭���� ���� �� �ִ� �ִ� 
	
	return ret; 
}

int main() {
	
	cin >> t;
	
	while(t--) {
		
		cin >> n;
		for (int i = 0; i < 2; i++) { // �� 
			for (int j = 0; j < n; j++) { // �� 
				cin >> arr[i][j]; // 
			}
		}
		
		for (int i = 0; i < n; i++) { // ���� ���� 
			for (int j = 0; j < 3; j++) { // ������ ���α�, 1�� ����, 2�඼��  
				dp[i][j] = -1;
			}
		}
		
		cout << go(0, 0) << '\n';
		
	}
	
	
	return 0;
}
