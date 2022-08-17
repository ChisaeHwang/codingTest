#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main() {
	
	int n, m;
	cin >> n;
	
	cin >> m;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + n, greater<int>()); 
	
   cout << arr[m - 1] << '\n';
	
}

