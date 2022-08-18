#include <iostream>

using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(11);
	// ÀÚ¸´¼ö °íÁ¤ 
	
	while(t--){
		int n, l, cost[1001];
		double minAvg = 101, avg;
		
		cin >> n >> l;
		
		for(int i = 0; i < n; i++){
			cin >> cost[i];
		}
		
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = i; j < n; j++){
				sum += cost[j];
				if(j - i >= l-1){
					avg = (double)sum / (j-i+1);
					if(avg < minAvg)
					{
						minAvg = avg;
					}
				}
			}
		}
		
		cout << minAvg << '\n';
		
	}
	
} 
