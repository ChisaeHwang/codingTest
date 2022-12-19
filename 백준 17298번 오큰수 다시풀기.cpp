#include <bits/stdc++.h>

using namespace std;


int a[1000001], ret[1000001];
stack<int> stk; 
int n;

int main() {
	
	cin >> n;
	
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while(stk.size() && a[stk.top()] < a[i]) { // �Էµ� ���� �����ʺ��� ũ��, stack�� ������ 
			ret[stk.top()] = a[i]; // ���������� ū���� �ֱ� 
			stk.pop();
		}
		// stack ������ �׳� push, ��ū�� �ƴϸ� �׳� Ǫ�� 
		stk.push(i); 
	}
	
	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
	
	return 0;
}
