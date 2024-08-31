#include <bits/stdc++.h>

using namespace std;

int t, n, k;
int arr[15][15]; // ¸îÈ£, ¸îÃþ 

int main() {
	
	cin >> t;
	
	for (int i = 0; i < 15; i++) {
		arr[0][i] = i;
	} 
	
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}
	
	while(t--) {
		cin >> n >> k;
		
		cout << arr[n][k] << '\n';
	}
	
	
	return 0;
}
