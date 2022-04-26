#include <iostream>
#include <algorithm>

int gcd(int a, int b) { // ����Լ� ������ �ִ� ����� ���ϴ� '��Ŭ���� ȣ����' 
	while(b != 0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

using namespace std; 

int main() { 
	
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		int arr[n];
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		
		long long result = 0;
		
		for(int i=0; i<n; i++){ // �� �ִ� ������� �� ���� ��ȸ�ϸ� ������ 
			for(int j=i+1; j<n; j++){
				result += gcd(arr[i], arr[j]);	
			}
		}
	
	cout << result << '\n';
	
	}
	
	return 0; 
}

