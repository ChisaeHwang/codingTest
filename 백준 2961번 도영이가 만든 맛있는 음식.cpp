#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, retS = 1, retB, ret = 987654321; 
int arr[11][2];
int visited[11];


void makePermutation(int s, int b, int depth) {
		
	if(n == depth){
		return;
	}
	
	if (abs(s - b) < ret) {
		ret = abs(s - b);
	}
	
	for(int i = 0; i < n; i++){
		if (visited[i]) continue;
		visited[i] = 1;
		makePermutation(s / arr[i][0], b - arr[i][1], depth + 1);
		visited[i] = 0;
	}
	
	return;
}

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0]; // �Ÿ�
		cin >> arr[i][1]; // ����
		retS *= arr[i][0];
		retB += arr[i][1];
	}
	
	// �ּҸ� ã�� ���ؼ�
	// �ִ� -> �ּ� �������� ������ 
	
	makePermutation(retS, retB, 0);
	
	
	cout << ret << '\n';
	
	return 0;
}

