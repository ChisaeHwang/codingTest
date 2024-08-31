#include <iostream>
#include <algorithm>

using namespace std;

int n[1000000];
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n[i];
	}		
	
	sort(n, n + t);
	
	for(int i=0; i<t; i++){
		cout << n[i] << '\n';
	}	
	
    return 0;
}

 
