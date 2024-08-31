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
		combi(i, b); // i값을 b에 계속 push
		b.pop_back(); // 넣은 i값을 뺀 후 ++i된 i값을 push 
	}
	
	return;
}

int main() {
	vector<int> b; // 빈값인 vector b 
	
	combi(-1, b);
	
	return 0;
}
