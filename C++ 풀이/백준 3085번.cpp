#include <iostream>
#include <vector>
#include <algorithm>

// 브루트 포스 : 모든 경우의 수를 다 해보는 알고리즘 ? 

using namespace std;

int check(vector<string> &a){
	int n= a.size();
	int ans = 1;
	for(int i=0; i<n; i++){
		int cnt = 1;
		for(int j=1; j<n; j++){
			if(a[i][j] == a[i][j-1]){
				cnt += 1;
			} else {
				cnt = 1;
			}
			if(ans < cnt) ans = cnt;
		}
		
		cnt = 1;
		
		for(int j=1; j<n; j++){
			if(a[j][i] == a[j-1][i]){
				cnt += 1;
			} else {
				cnb t = 1;
			}
			if(ans < cnt) ans = cnt;
		}
	}
	
	return ans;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j+1 < n){ // 오른쪽으로  
				swap(a[i][j], a[i][j+1]); // 교환 
				int temp = check(a);
				if(ans < temp) ans = temp;
				swap(a[i][j], a[i][j+1]);
			}
			if(i+1 < n){ // 아래로 
				swap(a[i][j], a[i+1][j]);
				int temp = check(a);
				if(ans < temp) ans = temp;
				swap(a[i][j], a[i+1][j]);
			}
		}
	}
	
	cout << ans << '\n'; 
	
	
	return 0;
}
