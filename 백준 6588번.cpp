#include <iostream>
using namespace std;

const int MAX = 1000000; // 모든 소수는 6n+1, 6n+5 

int prime[MAX]; // 소수 저장 
int pn; // 소수의 개수 
bool check[MAX+1]; // 지워졌으면 true 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i=2; i<=MAX; i++){
		if(check[i] == false){
			prime[pn++] = i;
			for (int j=i*2; j<=MAX; j+=i ){ // int 범위 때문에i*i 보다는 i*2 가 더 낫다 
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
			if (check[num - prime[i]] == false){ // 소수가 아니어서 지워지지 않았으면 (소수면) 
				cout << num << " = " << prime[i] << " + " << num - prime[i] << '\n';
				break;
			} 
		}
		
		
		
		
	}
	
	return 0; 
}
