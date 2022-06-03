#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t[21]; 
int p[21]; 
int n;
int temp=0;

void go(int day, int sum){
	if(day == n+1){
		if(temp < sum){
			temp = sum;
		}
		return;
	}
	if(day > n+1) return;
	go(day+t[day], sum+p[day]);
	go(day+1, sum);	
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> p[i];
	}
	
	go(1, 0);
	
	cout << temp << '\n';

	return 0;
} 
