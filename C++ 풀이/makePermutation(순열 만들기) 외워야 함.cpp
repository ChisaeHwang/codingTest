#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v) { // 참조값 V 
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
} 

// N 중에 R개를 뽑음 (순열) / depth를 호출해 재귀가능 
void makePermutation(int n, int r, int depth) {
	if (r == depth) { // depth의 값이 r과 같을 경우 return (최대 길이 이기때문) 
		printV(v);
		return;
	}
	
	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]); // 현재 깊이와 i번째 수를 swap
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]); 
 	}
 	
 	return;
}

int main() {
	
	for (int i = 0; i < 3; i++) v.push_back(a[i]); // index를 호출
	
	makePermutation(3, 3, 0); 
	
	return 0;
}

