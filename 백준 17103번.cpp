#include <iostream>
using namespace std;

const int MAX = 1000000; // ��� �Ҽ��� 6n+1, 6n+5 

int prime[MAX]; // �Ҽ� ���� 
int pn; // �Ҽ��� ���� 
bool check[MAX+1]; // ���������� true 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i=2; i<=MAX; i++){
		if(check[i] == false){
			prime[pn++] = i;
			for (int j=i*2; j<=MAX; j+=i ){ // int ���� ������i*i ���ٴ� i*2 �� �� ���� 
				check[j] = true;
			}
		}
	} 
	
	check[1] = true; 
    
	int num, t, result;
	cin >> t;
	
	while(t--){
		cin >> num;
		
		result = 0;
		
		for(int i=0; prime[i]<num; i++){ // �Ҽ��� ���� �Է¼� ���� ���� ���� 
			if(!check[num - prime[i]]){
				result++;
			}
		}
		
		if(!check[num/2]){ // num / 2�� �Ҽ��� ���, 3 + 3 = 6�� ���� 
			cout << result / 2 + 1 << '\n'; // �ߺ� ���� �� 1 ���ϱ� 
		} else {
			cout << result / 2 << '\n'; // �׳� �ߺ� ���� 
		}
	}
	
	return 0; 
}
