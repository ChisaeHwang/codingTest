#include <iostream>

using namespace std;

long long arr[101] = {0, 1, 1, };

long long go(int n){
	if(n < 3){
		return arr[n];
	}
	if(arr[n] == 0){
		arr[n] = go(n - 3) + go(n - 2);
	}
	
	return arr[n];
}

int main(){
	
	int t, n;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		cout << go(n) << '\n';
	}
	
	return 0;
}

// �Ǻ���ġ ������ ���� N�� Ŀ���� ���� ������ �����ϹǷ�, 
// �ݵ�� long long �ڷ����� ����ؾ��Ѵ�
