#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int num, sum=1, result=0;
	
	cin >> num;
	
	for(int i=1; i<=num; i++){
		sum *= i;
		
		if(i%5 == 0){
			result++;
		}
		if(i%25 == 0){
			result++;
		}
		if(i%125 == 0){
			result++;
		}
	}
	
	cout << result;
	
	return 0; 
}
