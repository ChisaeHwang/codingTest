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
	
	vector<int> d(n); // d[i] = i��°���� �� 
	vector<int> dr(n); // dr[i] = i��°���� ���� 
	
	for(int i=0; i<n; i++){
		d[i] =  arr[i]; // �������� �ʴ� ���
		if (i == 0) continue; 
		if(d[i] < d[i-1] + arr[i]){ // �����ϴ� ���
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
	
	
	// ���� ans�� �� �ֱ� 
	int ans = d[0];
	for (int i=1; i<n; i++){
		if (ans < d[i]){
			ans = d[i];
		}
	}
	
	// ù��°���� n-2 ���� �� �� �ֱ� 
	for (int i=1; i<n-1; i++){
		if (ans < d[i-1] + dr[i+1]){
			ans = d[i-1] + dr[i+1];
		}
	}
	
	cout << ans;
	
    return 0;
}

  
