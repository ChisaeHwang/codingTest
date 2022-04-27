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
	
	check[1] = true; 
    
	int num, t, result;
	cin >> t;
	
	while(t--){
		cin >> num;
		
		result = 0;
		
		for(int i=0; prime[i]<num; i++){ // 소수가 현재 입력수 보다 작을 동안 
			if(!check[num - prime[i]]){
				result++;
			}
		}
		
		if(!check[num/2]){ // num / 2가 소수일 경우, 3 + 3 = 6과 같이 
			cout << result / 2 + 1 << '\n'; // 중복 제거 후 1 더하기 
		} else {
			cout << result / 2 << '\n'; // 그냥 중복 제거 
		}
	}
	
	return 0; 
}
