#include <iostream>

using namespace std;

int d[10000];
int add(int num){
	d[0] = 1;
	d[1] = 1;
	for(int i=2; i<=num; i++){
		d[i] = d[i-1] + d[i-2] + d[i-3];
	}
	
	return d[num];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n;
    cin >> t;
    
    while(t--){
    	cin >> n;
    	add(n);
    	cout << d[n] << '\n';
	}

    return 0;
}

 
