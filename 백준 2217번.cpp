#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n;
	cin >> n;
	int k[n];
	for(int i=0; i<n; i++){
		cin >> k[i];
	}
	
	sort(k, k + n);
	
	int sum = 0;
	
	sum =  k[0] * n;
	
	for(int i=0; i<n; i++){
		sum = max(sum, k[i]*(n-i));
	}
	
	cout << sum;

    return 0;
}

 
