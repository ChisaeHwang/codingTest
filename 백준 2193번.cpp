#include <iostream>

using namespace std;

long long d[91] = {0};
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    d[1] = d[2] = 1; // 시작은 무조건 0이 아니어야 함 
    for(int i=3; i<=n; i++){ // 0 으로 끝난 경우 + 1 으로 끝난 경우 
    	d[i] = d[i-1] + d[i-2];
	}
	
	cout << d[n];

    return 0;
}

 
