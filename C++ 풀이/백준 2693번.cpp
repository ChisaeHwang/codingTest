#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[10] = {0,};
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
    	for(int i=0; i<10; i++){
	   		cin >> arr[i];
		}
		sort(arr, arr + 10);
	   	cout << arr[7] << " ";
	   	
	}
	
	return 0;
    
}


