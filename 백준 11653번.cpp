#include <iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int s=2; // 2 부터 소인수분해 
    
    while(n>1){
    	if(n%s==0){
    		cout << s << '\n'; // 소인수 분해 가능하면 출력 
    		n /= s; // 소인수분해 시킨만큼 나누기 
		} else {
			s++;	// 소인수분해 안될 때 마다 인수 하나씩 올려서 나누기 시도 
		}
	}
    
    return 0;
}
