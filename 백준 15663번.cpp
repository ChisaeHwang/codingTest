#include <iostream>
#include <algorithm>

using namespace std;

// 사용 true false // 결과값 
bool c[10]; int num[10]; int a[10]; 

void go(int idx, int n, int m) { // index번째를 채워야함 
	if (idx == m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return; //수열을 출력 
	}
	
	int cnt = -1; // 직전에 골랐던 수 저장 
	
	for (int i=0; i<n; i++){
		// 직전에 골랐던 수가 아니고 이미 고른 수가 아닐 경우에만 
		if(!c[i] && cnt != num[i]){
			c[i] = true; // 고르기 
			a[idx] = num[i]; // 배열 저장 
			cnt = num[i]; // 직전 수 저장 
			go(idx+1, n, m); // 순회 
			c[i] = false;	
		}
	}
}

// go(0, 1, n, m)

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	go(0, n, m);
	
	return 0; 
	
}
