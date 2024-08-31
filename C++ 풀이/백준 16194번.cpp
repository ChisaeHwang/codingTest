#include <iostream>
#include <algorithm> 

using namespace std;

int d[10000];
int p[10000];


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
   
    for(int i=1; i<=n; i++){ 
    	d[i] = -1;
    	d[0] = 0;
    	cin >> p[i];
    	for(int j=1; j<=i; j++){
			if(d[i] == -1 || d[i] > d[i-j] + p[j]){  
				d[i] = d[i-j] + p[j];
			}    		
		}
	}
	
	cout << d[n];

    return 0;
}

 
