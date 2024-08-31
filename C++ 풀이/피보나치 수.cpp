#include <iostream>
using namespace std;

//Dynamic Programming

int memo[100];
int fibonacci(int n){
	if(n <= 1){
		return n;
	} else {
		memo[n] = fibonacci(n-1) + fibonacci(n-2);
		return memo[n];
	}
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}
