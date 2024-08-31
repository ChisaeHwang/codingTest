#include<bits/stdc++.h>
using namespace std; 


int n; 
int count;

int main() {
	
	vector<int> v;
	cin >> n;
	
	int points[100001][2];
	
	for (int i = 0; i < n; i++){
		cin >> points[i][0] >> points[i][1];
	}
	
	int ret = 0;
	int countX[100001];
	int countY[100001];
	
	for (int i = 0; i < n; i++) {
		int count_x = points[i][0];
		int count_y = points[i][1];
		

		if ( count_x > 0) {
			countX[i] = 1;
		} else {
			countX[i] += 1;
		}
		
		if (count_y> 0) {
			countY[i] = 1;
		} else {
			countY[i] += 1;
		}
	}
	
	for (int i = 0; i < n; i++){
		long valueX = countX[i] - 1;
		long valueY = countY[i] - 1;
		
		ret += valueX * valueY;
	}
	
	cout << ret << '\n';
 	
	
	
	return 0;
}
