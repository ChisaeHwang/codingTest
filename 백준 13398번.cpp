#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	vector<int> d(n); // d[i] = i번째에서 끝 
	vector<int> dr(n); // dr[i] = i번째에서 시작 
	
	for(int i=0; i<n; i++){
		d[i] =  arr[i]; // 연속하지 않는 경우
		if (i == 0) continue; 
		if(d[i] < d[i-1] + arr[i]){ // 연속하는 경우
			d[i] = d[i-1] + arr[i];
		}	
	}
	
	for (int i=n-1; i>=0; i--){
		dr[i] = arr[i];
		if (i == n-1) continue;
		if(dr[i] < dr[i+1] + arr[i]){
			dr[i] = dr[i+1] + arr[i];
		}
	}
	
	
	// 값들 ans에 다 넣기 
	int ans = d[0];
	for (int i=1; i<n; i++){
		if (ans < d[i]){
			ans = d[i];
		}
	}
	
	// 첫번째부터 n-2 까지 비교 후 넣기 
	for (int i=1; i<n-1; i++){
		if (ans < d[i-1] + dr[i+1]){
			ans = d[i-1] + dr[i+1];
		}
	}
	
	cout << ans;
	
    return 0;
}

  
