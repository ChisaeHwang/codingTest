#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51]; 
int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	
	int ret = 1;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 1; k < min(n, m); k++){ // ���� 1���� �׳� n m �ְ���ġ���� ����Ž�� 
				if (i + k < n && j + k < m 
				&& arr[i + k][j] == arr[i][j] 
				&& arr[i + k][j + k] == arr[i][j] 
				&& arr[i][j + k] == arr[i][j]) {
					// ���� ��ġ���� k ��ŭ ���ص� ���� �ʴ���, ���� ��ġ���� ����, �ϴ�, �밢�� ������� üũ
					ret = max(ret, k + 1); // ������� �ְ��̶� k���� �Ÿ��� ���� �� 
					
				} 
			}
		}
	}
	
	ret = ret * ret;
	
	printf("%d", ret); 
	
	return 0;
}
