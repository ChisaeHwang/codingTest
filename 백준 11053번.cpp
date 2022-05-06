#include <iostream>
#include <algorithm>
using namespace std;

int d[1000];
int arr[1000];
int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n, ans=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		d[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i]){ // j < i ÀÌ´Ù  
				d[i] = max(d[i], d[j] + 1);
				cout << d[i];
			}
		}
		ans = max(ans,d[i]);
	}
	
	cout << ans;
	
    return 0;
}

  
