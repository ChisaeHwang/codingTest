#include <bits/stdc++.h>
using namespace std;

int main() {
	
    while(true) {
    	
    	int n;
    	
    	cin >> n;
    	
    	if(n == 0) break;
    	
    	int currentSum = 0, maxSum = -10001; // 최소 수익보다 낮은 값으로 초기
    	
    	for(int i = 0; i < n; i++) {
    		int num;
			cin >> num;
    		currentSum = max(num, currentSum + num); // 현재 수익을 포함한 합 vs 현재 수익만
            maxSum = max(maxSum, currentSum); // 최대 수익 업데이트
            cout << currentSum << '\n';
		}
		
		cout << maxSum << '\n';
    	   	
	}
    
    return 0;
}

