#include <iostream>

using namespace std;

int arr[100001];

int main() {
	
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 1; i <= n; i++){
		arr[i] += arr[i - 1];
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		
		cout << arr[b - 1] - arr[a - 2] << '\n';
	}
	
	
	return 0; 
}
