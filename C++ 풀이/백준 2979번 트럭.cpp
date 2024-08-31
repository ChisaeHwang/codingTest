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
		if (cnt[i]) { // �ش� �迭�� Ʈ���� �����Ǿ� ���� ��� 
			if (cnt[i] == 1) ret += A; // �� �� ���� 
			if (cnt[i] == 2) ret += B * 2; // �� �� ���� 
			if (cnt[i] == 3) ret += C * 3;	 // �� �� ���� 
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}
