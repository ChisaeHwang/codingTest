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
		cin >> arr[i]; // 원하는 동전 입력 
	}
	
	for(int i=num-1; i>=0; i--){ // 내림차순으로 순회 
		result += k / arr[i]; // 큰 수로 나눈 후 
		k = k % arr[i]; // 나머지를 k에 저장하고 계속 순회 
	}
	
	cout << result; // 이후 sum을 출력하면 사용한 지폐 수 계산 완료 
	
	return 0; 
}
