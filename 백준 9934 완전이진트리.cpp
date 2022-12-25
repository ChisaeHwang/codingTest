#include <bits/stdc++.h>

using namespace std;

int n, _end;
vector<int> ret[14];
int arr[1021];

// inOrder, postOrder, preOrder�� �ܿ��ִ°� ���� 

void inOrder(int s, int e, int Lv) {
	if (s > e) return;
	if (s == e) {
		ret[Lv].push_back(arr[e]); // s�� ���� ������� 
		return;
	}
	
	int mid = (s + e) / 2; // s + e�� ������ Ȧ���� ���ͼ� mid���� ���� �� �ִ�
	ret[Lv].push_back(arr[mid]);
	
	// ���� ������ ����Ž�� 
	inOrder(s, mid - 1, Lv + 1);
	// ���� ������ ������ Ž�� 
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
