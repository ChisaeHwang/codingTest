#include <iostream>
#include <algorithm> 
#define MAX(x,y,z) (x > y ? (x > z ? x : z) : (y > z ? y : z))

using namespace std;

int d[10000];
int p[10000];


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
   
    for(int i=1; i<=n; i++){
    	cin >> p[i];
    	for(int j=1; j<=i; j++){ // 카드 1개를 p[1]에 구매 -> 남은 카드 수 i-1 -> p[1] + d[i-1] 
			d[i] = max(d[i], d[i-j] + p[j]); // 카드 N개를 p[N]에 구매 -> 남은 카드 수 i-N -> p[N] + d[i-N] 
		}
	}
	
	cout << d[n] << ' ';

    return 0;
}

 
