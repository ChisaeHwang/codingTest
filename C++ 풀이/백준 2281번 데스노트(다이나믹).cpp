#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int Name[1001];
int dp[1001][1001];

int go(int name, int len) { // �ڿ� ��ĭ ���� ����
	if(name >= n) return 0;
	int result = dp[name][len];
	if(result != -1){
		return result;
	}
	
	// ��ĭ ������ ���� ��� 
	result = (m - len + 1)*(m - len + 1) + go(name+1, Name[name] + 1);
	
	// ���� �ٿ� ���� ��� 
	if(len + Name[name] <= m){
		result = min(result, go(name+1, len + Name[name] + 1));
	}
	
	return result;
}
 

int main(){
		
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> Name[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
	cout << go(0, 0) << '\n';
	
	return 0;
} 
