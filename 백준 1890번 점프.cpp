#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Dynamic Programming

#define MAX 987654321

using namespace std;

int board[100][100];
long long int dp[100][100];
int n;

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	
	dp[0][0] = 1; // ������ ���� �ؾ��ϹǷ� 1�� �ʱ�ȭ 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int jump = board[i][j]; // board 2���� �迭�� jump�� �ֱ�
			if(i != n-1 && i + jump < n){
				dp[i+jump][j] += dp[i][j];
			} 
			if(j != n-1 && j + jump < n){
				dp[i][j+jump] += dp[i][j];
			}
		}
	}
	
	cout << dp[n-1][n-1] << '\n';
	
	
	return 0;
} 
