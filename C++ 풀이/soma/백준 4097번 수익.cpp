#include <bits/stdc++.h>
using namespace std;

int main() {
	
    while(true) {
    	
    	int n;
    	
    	cin >> n;
    	
    	if(n == 0) break;
    	
    	int currentSum = 0, maxSum = -10001; // �ּ� ���ͺ��� ���� ������ �ʱ�
    	
    	for(int i = 0; i < n; i++) {
    		int num;
			cin >> num;
    		currentSum = max(num, currentSum + num); // ���� ������ ������ �� vs ���� ���͸�
            maxSum = max(maxSum, currentSum); // �ִ� ���� ������Ʈ
            cout << currentSum << '\n';
		}
		
		cout << maxSum << '\n';
    	   	
	}
    
    return 0;
}

