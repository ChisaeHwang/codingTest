#include <iostream>
#include <algorithm>

using namespace std;

// 사전순으로 사용할 경우 유용 
// 결과값 
int a[10]; 

void go(int idx, int selected, int n, int m) { // index번째를 채워야함 
	if (selected == m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return; //수열을 출력 
	}
	
	if(idx > n) return;
	a[selected] = idx; // idx 결과 추가 
	go(idx+1, selected+1, n, m);
	a[selected] = 0 // idx 결과 추가 안함
	go(idx+1, selected, n, m); 
	
}

// go(0, 1, n, m)

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	
	return 0; 
	
}
