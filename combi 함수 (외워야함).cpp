#include <bits/stdc++.h>

using namespace std;

int n = 5;
int k = 3;
int a[5] = {1, 2, 3, 4, 5};

void print (vector<int> b) {
	for (int i : b) cout << i << " ";
	cout << '\n';
}

void combi (int start, vector<int> b) {
	if (b.size() == k) {
		print(b);
		return;
	}
	
	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b); // i���� b�� ��� push
		b.pop_back(); // ���� i���� �� �� ++i�� i���� push 
	}
	
	return;
}

int main() {
	vector<int> b; // ���� vector b 
	
	combi(-1, b);
	
	return 0;
}
