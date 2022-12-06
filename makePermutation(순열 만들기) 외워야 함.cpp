#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v) { // ������ V 
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
} 

// N �߿� R���� ���� (����) / depth�� ȣ���� ��Ͱ��� 
void makePermutation(int n, int r, int depth) {
	if (r == depth) { // depth�� ���� r�� ���� ��� return (�ִ� ���� �̱⶧��) 
		printV(v);
		return;
	}
	
	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]); // ���� ���̿� i��° ���� swap
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]); 
 	}
 	
 	return;
}

int main() {
	
	for (int i = 0; i < 3; i++) v.push_back(a[i]); // index�� ȣ��
	
	makePermutation(3, 3, 0); 
	
	return 0;
}

