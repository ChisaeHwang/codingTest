#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	
	int n, c;
	
	vector<int>house(n, 0);
	
	for(int i = 0; i < n; i++){
		cin >> house[i];
	}
	
	sort(house.begin(), house.end());
	
	int low = 0, high = house[n - 1];
	
	while(low <= high) 
	{
		int cnt = 1;
		int prev = 0;
		int mid = (low + high) / 2;
		
		for (int i = 1; i < n; i++){
			if (house[i] - house[prev] >= mid){
				prev = i;
				cnt++;
			}
		}
		
		if (cnt >= c) 
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}
	
	cout << high << '\n';
	
	return 0;
}
