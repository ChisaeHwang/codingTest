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
    
    int min, max;
    
    
    
    int num = 0; 
    
    while(t--){
    	
	    int n;
	    cin >> n;
	    
	    if(prime(n)){
	    	num++;
		}
	} 
	
	cout << num << '\n';
	
	return 0; 
}
