#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[31][2];

int main() {
	
	int n, m;
	cin >> n >> m;
	arr[1][0] = 1;
	arr[2][1] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}
	
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= m; j++){
			if(i * arr[n][0] + j * arr[n][1] == m){
				cout << i << '\n' << j;
				return 0;
			}
			if(i * arr[n][0] + j * arr[n][1] > m) {
				break;
			}	
		}		
	} 
	
}	
