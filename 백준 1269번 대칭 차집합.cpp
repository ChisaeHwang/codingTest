#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main() {
	
	int n, m;
	map<int, bool> arr;
	int num;
	
	cin >> n >> m;
	
	for(int i = 0; i < n + m; i++){
		
		cin >> num;
		
		if(arr[num] == true){
			arr.erase(num);
		} else {
			arr[num] = true;
		}
	}
	
	cout << arr.size() << '\n';
	
	return 0;
}
