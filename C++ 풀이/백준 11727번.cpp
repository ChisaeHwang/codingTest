#include <iostream>

using namespace std;

int D[10000];
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    D[0] = 1;
    D[1] = 1;
    for(int i=2; i<=n; i++){
    	D[i] = (2*D[i-2] + D[i-1]) % 10007;
	}
	
	cout << D[n];
    
    return 0;
}
