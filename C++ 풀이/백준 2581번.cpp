#include <iostream>
using namespace std;

bool prime(int n){ // 에라토스테네스의 체 
	if (n < 2){
		return false;
	}
	for (int i=2; i*i<=n; i++){
		if (n % i == 0){
			return false;
		}
	}
	
	return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int min = 0, max = 0;
	
	bool first = false;

    int m, n;
    
    cin >> m >> n;
    
    for(int i=m; i<=n; i++){
    	if(prime(i)){
    		if(!first){
    			min += i;
    			first = true;
			}
    		max += i;	
		} 
	} 
	
	if (min == 0){
		cout << -1 << '\n';
	} else{
		cout << max << '\n' << min;
	}  
	
	return 0; 
}
