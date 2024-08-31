#include <iostream>
#include <algorithm>

using namespace std;

// 사용 trye false // 결과값 
bool c[10]; int a[10]; 

void go(int idx, int n, int m) { // index번째를 채워야함 
	if (idx == m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		
		cout << '\n';
		return; //수열을 출력 
	}
	for (int i=1; i<=n; i++){
		if(c[i]) continue;
		c[i] = true; a[idx] = i;
		go(idx+1, n, m);
		c[i] = false;
	}
}

// go(0, n, m)

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	
	return 0; 
	
}
