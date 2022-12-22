#include <bits/stdc++.h>

using namespace std;

int n, m, ret = 987654321;
char arr[51][51];

int main() {


	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m ; j++){
			if (i + 8 <= n && j + 8 <= m) {
				int bSum = 0;
				int wSum = 0;
				for (int k = i; k < i + 8; k++){
					for (int l = j; l < j + 8; l++){
						if ((k + l) % 2 == 0) { // 맨 왼쪽 위칸이 흰색이 경우 
							if(arr[k][l] == 'W') bSum++; // 흰색 들어가야 하는데 검은색이 있네? 
							else wSum++;
						} else { // 맨 왼쪽 위칸에 검은색이 경우 
							if(arr[k][l] == 'W') wSum++; 
							else bSum++;
						}
					}	
				}
				
				ret = min(ret, min(bSum, wSum));
			}
		}
	}
	
	cout << ret << '\n';
	
	return 0;
} 
