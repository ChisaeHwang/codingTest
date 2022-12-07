 #include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int m;
int A, B, C; 
int cnt[101];
int ret;

int main() {
	
	cin >> A >> B >> C;
	
	for (int i = 0; i < 3; i++){
		cin >> n >> m;
		
		for (int j = n; j < m; j++) {
			cnt[j]++;
		}
	}
		
	for (int i = 0; i < 100; i++){
		if (cnt[i]) { // 해당 배열에 트럭이 주차되어 있을 경우 
			if (cnt[i] == 1) ret += A; // 한 대 주차 
			if (cnt[i] == 2) ret += B * 2; // 두 대 주차 
			if (cnt[i] == 3) ret += C * 3;	 // 세 대 주차 
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}
