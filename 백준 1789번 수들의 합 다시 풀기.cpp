#include <bits/stdc++.h>

using namespace std;

long long s, ret, sum;

int main() {
	
	cin >> s;
	
	long long num = 1;
	long long cnt = 0;
	
	while(true) {
		sum += num;
		cnt++;
			if(sum > s) {
				cnt--;
				break;
			}
		num++;
	}
	
	cout << cnt << '\n';
	
	return 0;
} 
