#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> d(1001); // 수열 
vector<int> arr(1001); // 수열 길이 
vector<int> v(1001); // 수열 담을 공간 


void go(int idx) {
	if(idx == -1){
		return;
	}
	go(v[idx]);
	cout << arr[idx] << ' ';
}

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n, ans=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++){
		v[i] = -1;
		d[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && d[i] < d[j] + 1){ // j < i 이다  
				d[i] = d[j] + 1; // d[i]++
				v[i] = j;
			}
		}
		ans = max(ans,d[i]);
	}
	
	cout << ans << '\n';
	
	int idx = 0;
	
	for(int i=0; i<n; i++){
			idx = i;
	}
	
	go(idx);
	
    return 0;
}

  
