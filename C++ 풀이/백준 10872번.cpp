#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int num, sum=1;
	
	cin >> num;
	
	for(int i=1; i<=num; i++){
		sum *= i;
	}
	
	cout << sum;
	
	return 0; 
}
