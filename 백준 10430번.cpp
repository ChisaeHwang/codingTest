#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int arr[11];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int num, k;
	cin >> num >> k;
	
	int result = 0;
	
	for(int i=0; i<num; i++){
		cin >> arr[i]; // ���ϴ� ���� �Է� 
	}
	
	for(int i=num-1; i>=0; i--){ // ������������ ��ȸ 
		result += k / arr[i]; // ū ���� ���� �� 
		k = k % arr[i]; // �������� k�� �����ϰ� ��� ��ȸ 
	}
	
	cout << result; // ���� sum�� ����ϸ� ����� ���� �� ��� �Ϸ� 
	
	return 0; 
}
