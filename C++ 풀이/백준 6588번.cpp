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
    
	int num;
	
	while(true){
		cin >> num;
		if (num == 0){
			break;
		}
		for (int i=1; i<pn; i++){
			if (check[num - prime[i]] == false){ // �Ҽ��� �ƴϾ �������� �ʾ����� (�Ҽ���) 
				cout << num << " = " << prime[i] << " + " << num - prime[i] << '\n';
				break;
			} 
		}
		
		
		
		
	}
	
	return 0; 
}
