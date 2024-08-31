#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
int d[101];
int lose[21];
int joy[21];

void dp(){
    for(int i=1; i<=n; i++){
        for(int j=100; j>lose[i]; j--){
            d[j] = max(d[j], d[j-lose[i]] + joy[i]);
        }
    }
    
    cout << d[100] << "\n";
}

int main(int argc, const char * argv[]) {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> lose[i];
    }
    
    for(int i=1; i<=n; i++){
        cin >> joy[i];
    }
    
    dp();
    
    return 0;
}
