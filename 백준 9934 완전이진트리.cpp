#include <bits/stdc++.h>

using namespace std;

int n, _end;
vector<int> ret[14];
int arr[1021];

// inOrder, postOrder, preOrder는 외워주는게 좋다 

void inOrder(int s, int e, int Lv) {
	if (s > e) return;
	if (s == e) {
		ret[Lv].push_back(arr[e]); // s가 들어가도 상관없음 
		return;
	}
	
	int mid = (s + e) / 2; // s + e는 무조건 홀수가 나와서 mid값을 얻을 수 있다
	ret[Lv].push_back(arr[mid]);
	
	// 범위 나누기 왼쪽탐색 
	inOrder(s, mid - 1, Lv + 1);
	// 범위 나누기 오른쪽 탐색 
	inOrder(mid + 1, e, Lv + 1);
	
	return; 
} 


int main() {
	
	cin >> n;
	_end = (int)pow(2, n) - 1;
	
	for (int i = 0; i < _end; i++){
		cin >> arr[i];
	}
	
	inOrder(0, _end, 1);
	
	for (int i = 1; i <= n; i++){
		for (int j : ret[i]) {
			cout << j << " ";
		}
		cout << '\n';
	}
	
	
	return 0;
}
